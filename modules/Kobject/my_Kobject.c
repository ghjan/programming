#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");

/*��Ӧ��kobject��Ŀ¼�µ�һ���ļ�,Name��Ա�����ļ���*/
struct attribute test_attr =
{
	.name ="dong_config",
	.mode = S_IRWXUGO,
};

static struct attribute *def_attrs[] = 
{
	&test_attr,
	NULL,//ֻ��һ���ļ���������� NULL
};

/*�����ļ�ʱִ�еĲ���*/
ssize_t	kobj_test_show(struct kobject *kobject, struct attribute *attr,char *buf)
{
	printk("have show\n");
	printk("attrname:%s\n",attr->name);

	 sprintf(buf,"%s\n",attr->name);
     return strlen(attr->name)+2;//ΪʲôҪ +2   ��Ϊ���ǳ��˷��� ���ֵĳ���  ��Ҫ���� \n
}

/*��д�ļ�ʱִ�еĲ���*/
ssize_t	kobj_test_store(struct kobject *kobject,struct attribute *attr,const char *buf, size_t count)
{
	printk("have store\n");
	printk("write:%s\n",buf);
	return count;
	
}

void obj_test_release(struct kobject *kobj)
{
	printk("release\n");
}

//kobject����Ĳ���
struct sysfs_ops obj_test_sysops =
{
	.show = kobj_test_show,
	.store = kobj_test_store,
};

/*����kobject�����һЩ���Լ���Ӧ�Ĳ���*/
struct kobj_type ktype = 
{
	.release 		=	obj_test_release,
	.sysfs_ops		=	&obj_test_sysops,
	.default_attrs	=	def_attrs,
};

struct kobject kobj;//����kobject����
static int kobj_test_init()
{
	printk("Kobject test init\n");
	kobject_init_and_add(&kobj,&ktype,NULL,"kobject_test");//��ʼ��kobject����kobj,������ע�ᵽlinuxϵͳ
	
	return 0;
}

static void kobj_test_exit()
{
	printk("Kobject test exit \n");
	kobject_del(&kobj);
}

module_init(kobj_test_init);
module_exit(kobj_test_exit);



