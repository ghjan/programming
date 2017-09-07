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

struct class *second_irq_class;
struct class_device *second_irq_class_dev;

static DECLARE_WAIT_QUEUE_HEAD(button_waitq);/*�ȴ�����*/

/* �ж��¼���־, �жϷ����������1��second_irq_read������0 */
static volatile int ev_press = 0;

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

	ev_press = 1;                  /* ��ʾ�жϷ����� */
    wake_up_interruptible(&button_waitq);   /* �������ߵĽ��� */
	
	return IRQ_HANDLED;
}

static int second_irq_open(struct inode *inode, struct file *file)
{
	request_irq(IRQ_EINT8,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K1",&pins_desc[0] );
	request_irq(IRQ_EINT11,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K2",&pins_desc[1] );
	request_irq(IRQ_EINT13,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K3",&pins_desc[2] );
	request_irq(IRQ_EINT14,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K4",&pins_desc[3] );
	

	return 0;
}

ssize_t second_irq_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	if(size!=1)
	return -EINVAL;

	/* ���û�а�������������*/
	wait_event_interruptible(button_waitq, ev_press);

	/* ����а�������������*/
	copy_to_user(buf,&key_val, size);
	ev_press = 0;
	
	return 0;
}

int second_irq_close (struct inode *inode, struct file *file)
{
	free_irq(IRQ_EINT8, &pins_desc[0] );
	free_irq(IRQ_EINT11,&pins_desc[1] );
	free_irq(IRQ_EINT13,&pins_desc[2] );
	free_irq(IRQ_EINT14,&pins_desc[3] );
	return 0;
}

static struct file_operations second_irq_fops = {  
	.owner  =   THIS_MODULE,    /* ����һ���꣬�������ģ��ʱ�Զ�������__this_module���� */ 
	.open   =   second_irq_open,    
	.read   =  second_irq_read,
	.release =second_irq_close,
};

int major;

int second_irq_init()
{		
	
	major = register_chrdev(0 , "irq",&second_irq_fops );

	second_irq_class = class_create(THIS_MODULE,"irq");
	second_irq_class_dev = device_create(second_irq_class, NULL, MKDEV(major, 0), NULL, "irq_dev"); 
	
	printk("major = %d \n",major);
	
	return 0;
}
void second_irq_exit()
{	
	unregister_chrdev(major,"irq");
	class_destroy(second_irq_class);
	class_destroy(second_irq_class_dev);
}


module_init(second_irq_init);
module_exit(second_irq_exit);

MODULE_LICENSE("GPL");  
