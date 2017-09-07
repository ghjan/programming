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

struct class *fifth_irq_class;
struct class_device *fifth_irq_class_dev;

static DECLARE_WAIT_QUEUE_HEAD(button_waitq);/*ע��button_waitq ����ȴ�����*/

/* �ж��¼���־, �жϷ����������1��fifth_irq_read������0 */
//static volatile int ev_press = 0;

static struct fasync_struct *button_async;


static int key_val;

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
	
    kill_fasync(&button_async,SIGIO,POLL_IN);//���а���������ʱ��������֪ͨӦ�ó���	(����Ӧ�ó���)
	
	return IRQ_HANDLED;
}

static int fifth_irq_open(struct inode *inode, struct file *file)
{
	request_irq(IRQ_EINT8,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K1",&pins_desc[0] );
	request_irq(IRQ_EINT11,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K2",&pins_desc[1] );
	request_irq(IRQ_EINT13,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K3",&pins_desc[2] );
	request_irq(IRQ_EINT14,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K4",&pins_desc[3] );
	
	return 0;
}

int fifth_irq_close(struct inode *inode, struct file *file)//�ر�Ӧ�ó���ʱ�ͻ�����������
{
	free_irq(IRQ_EINT8, &pins_desc[0] );
	free_irq(IRQ_EINT11,&pins_desc[1] );
	free_irq(IRQ_EINT13,&pins_desc[2] );
	free_irq(IRQ_EINT14,&pins_desc[3] );
	
	printk("�ж�close\n");
	return 0;
}

ssize_t fifth_irq_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	if(size!=1)
	return -EINVAL;

	copy_to_user(buf,&key_val, size);
	
	return 0;
}

int fifth_irq_fasync(int fd, struct file *file, int on)//����ģ���ж��ģ�鶼������������
{
	printk("driver: fifth_drv_fasync\n");
	return fasync_helper(fd, file, on, &button_async);//��ʼ�����ͷŶ����õ�fasync_helper
}

static struct file_operations fifth_irq_fops = {  
	.owner 		=   THIS_MODULE,    /* ����һ���꣬�������ģ��ʱ�Զ�������__this_module���� */ 
	.open 		=   fifth_irq_open,    
	.release	=	fifth_irq_close,
	.read 		=  	fifth_irq_read,
	.fasync		= 	fifth_irq_fasync,
};

int major;

int fifth_irq_init()
{		
	
	major = register_chrdev(0 , "irq",&fifth_irq_fops );

	fifth_irq_class = class_create(THIS_MODULE,"irq");
	fifth_irq_class_dev = device_create(fifth_irq_class, NULL, MKDEV(major, 0), NULL, "irq_dev"); 
	
	printk("major = %d \n",major);
	
	return 0;
}
void fifth_irq_exit()
{	
	unregister_chrdev(major,"irq");
	class_destroy(fifth_irq_class);
	device_unregister(fifth_irq_class_dev);
}

module_init(fifth_irq_init);
module_exit(fifth_irq_exit);

MODULE_LICENSE("GPL");  

