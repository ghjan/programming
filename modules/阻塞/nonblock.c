#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <linux/irq.h>
#include <asm/irq.h>
#include <linux/interrupt.h>
#include <asm/uaccess.h>
#include <mach/regs-gpio.h>
#include <mach/hardware.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/miscdevice.h>
#include <linux/sched.h>
#include <linux/gpio.h>

struct class *seven_drv_class;
struct class_device *seven_drv_class_device;
static DECLARE_MUTEX(button_lock);//���廥����

static DECLARE_WAIT_QUEUE_HEAD(button_waitq);
/* �ж��¼���־, �жϷ����������1��sixth_drv_read������0 */
static volatile int ev_press = 0;
static unsigned char key_val;

struct pin_desc{
	unsigned int pin;
	unsigned int key_val;
};

struct pin_desc pins_desc[4] = {
	{S3C2410_GPG(0),0x1},
	{S3C2410_GPG(3),0x2},
	{S3C2410_GPG(5),0x3},
	{S3C2410_GPG(6),0x4},
};

static irqreturn_t buttons_irq(int irq, void *dev_id)
{
	struct pin_desc *pindesc = (struct pin_desc *)dev_id;
	unsigned int pinval = 0;
	
	pinval = s3c2410_gpio_getpin(pindesc->pin);

	if(pinval)
	{
		/* �ɿ�*/
		key_val = 0x80 | pindesc->key_val;		/* ���ɿ���ʱ�����ü�ֵΪ0x81*/
	}
	else
	{
		/* ����*/
		key_val = pindesc->key_val;			/* �����µ�ʱ�����ü�ֵΪ0x01*/
	}
	
    ev_press = 1;                  /* ��ʾ�жϷ����� */
    wake_up_interruptible(&button_waitq);   /* �������ߵĽ��� */
	
	return IRQ_HANDLED;
}

static int seven_irq_open(struct inode *inode, struct file *file)
{	
	if(file->f_flags & O_NONBLOCK)/*�����Ƿ�����*/
	{
		if(down_trylock(&button_lock))/*���Ի�ȡ�ź���  �������� ֱ�ӷ���*/
		return -1;//Ӧ�ó����� read�ķ���ֵ ��������������õ�
	}
	else
	{
		down(&button_lock);//��ȡ�ź���
	}
	
	request_irq(IRQ_EINT8,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K1",&pins_desc[0] );
	request_irq(IRQ_EINT11,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K2",&pins_desc[1] );
	request_irq(IRQ_EINT13,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K3",&pins_desc[2] );
	request_irq(IRQ_EINT14,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K4",&pins_desc[3] );
	
	return 0;
}

int seven_irq_close(struct inode *inod, struct file *file)
{
	up(&button_lock);//�ͷ��ź���
	
	free_irq(IRQ_EINT8, &pins_desc[0] );
	free_irq(IRQ_EINT11,&pins_desc[1] );
	free_irq(IRQ_EINT13,&pins_desc[2] );
	free_irq(IRQ_EINT14,&pins_desc[3] );
}

ssize_t seven_irq_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	if(size!=1)
	return -EINVAL;

	if(file->f_flags & O_NONBLOCK)//����Ƿ�����
	{
		if( !ev_press)//�ж���û���ж�
		return -2;//û�оͷ���
	}
	else
	{
		wait_event_interruptible(button_waitq,ev_press);
	}

	/*����а�������*/
	copy_to_user(buf,&key_val, size);
	ev_press = 0;
	
	return 0;
}

struct file_operations seven_drv_fops = {
	.owner 		=  	THIS_MODULE,    /* ����һ���꣬�������ģ��ʱ�Զ�������__this_module���� */ 
	.open 		=   	seven_irq_open,    
	.release		=	seven_irq_close,
	.read 		=  	seven_irq_read,
};

int major;
int seven_drv_init()
{
	major = register_chrdev( 0, "KEY_irq", &seven_drv_fops);

	seven_drv_class = class_create(THIS_MODULE,"irq");
	seven_drv_class_device = device_create(seven_drv_class,NULL,MKDEV(major, 0),NULL,"irq");

	printk("major = %d\n",major);
	return 0;
}
void seven_drv_exit()
{
	unregister_chrdev(major,"irq");
	class_destroy(seven_drv_class);
	device_unregister(seven_drv_class_device);
}


module_init(seven_drv_init);
module_exit(seven_drv_exit);

MODULE_LICENSE("GPL");

