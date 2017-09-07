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
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/miscdevice.h>
#include <linux/sched.h>
#include <linux/gpio.h>

struct class *fourth_irq_class;
struct class_device *fourth_irq_class_dev;

static DECLARE_WAIT_QUEUE_HEAD(button_waitq);/*ע��button_waitq ����ȴ�����*/

int  s = 0;

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

    wake_up_interruptible(&button_waitq);   /* �������ߵĽ��� */
	s = 1;
	return IRQ_HANDLED;
}

static int fourth_irq_open(struct inode *inode, struct file *file)
{
	request_irq(IRQ_EINT8,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K1",&pins_desc[0] );//pins_desc����ṹ�彫����buttons_irq�ڶ�������
	request_irq(IRQ_EINT11,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K2",&pins_desc[1] );
	request_irq(IRQ_EINT13,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K3",&pins_desc[2] );
	request_irq(IRQ_EINT14,buttons_irq,IRQ_TYPE_EDGE_BOTH,"K4",&pins_desc[3] );
	
	return 0;
}

ssize_t fourth_irq_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	if(size!=1)
	return -EINVAL;

	copy_to_user(buf,&key_val, size);
	
	s = 0;
	
	return 0;
}

unsigned int fourth_irq_poll(struct file *file, struct poll_table_struct *wait)
{
	unsigned int mask = 0;
	
	/* ��button_waitq( �ȴ�����) ���뵽poll_table ��ȥ*/
	poll_wait(file,&button_waitq,wait);

	if(s == 1)
	mask |= POLLIN | POLLRDNORM;/*�ֱ����豸�ɶ������ݿɶ�*/
	//����ֵ�� �ɶ��豸�ĸ���    ���Ǻ����� ���д���һ�����ں˴���
	return mask;
}


int fourth_irq_close (struct inode *inode, struct file *file)
{
	free_irq(IRQ_EINT8, &pins_desc[0] );
	free_irq(IRQ_EINT11,&pins_desc[1] );
	free_irq(IRQ_EINT13,&pins_desc[2] );
	free_irq(IRQ_EINT14,&pins_desc[3] );
	printk("\nhave been closed\n");
	return 0;
}

static struct file_operations fourth_irq_fops = {  
	.owner 	=   	THIS_MODULE,    /* ����һ���꣬�������ģ��ʱ�Զ�������__this_module���� */ 
	.open 	=   	fourth_irq_open,    
	.read 	=  		fourth_irq_read,
	.release 	=	fourth_irq_close,
	.poll     	=	fourth_irq_poll,
};

int major;

int fourth_irq_init()
{		
	
	major = register_chrdev(0 , "irq",&fourth_irq_fops );

	fourth_irq_class = class_create(THIS_MODULE,"irq");
	fourth_irq_class_dev = device_create(fourth_irq_class, NULL, MKDEV(major, 0), NULL, "irq_dev"); 
	
	printk("major = %d \n",major);
	
	return 0;
}
void fourth_irq_exit()
{	
	unregister_chrdev(major,"irq");
	device_unregister(fourth_irq_class_dev);
	class_destroy(fourth_irq_class);
}


module_init(fourth_irq_init);
module_exit(fourth_irq_exit);

MODULE_LICENSE("GPL");  
