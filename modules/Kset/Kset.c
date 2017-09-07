#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/stat.h>
#include <linux/kobject.h>

MODULE_LICENSE("GPL");


int kset_filter(struct kset *kset, struct kobject *kobj)
{
		printk("Filter: kobj %s.\n",kobj->name);
		return 0;							//���Ϊ0		�������������Ͳ�ִ��
}

const char *kset_name(struct kset *kset, struct kobject *kobj)//���û��ռ䴫  �ַ���
{
        static char buf[20];
        printk("Name: kobj %s.\n",kobj->name);
        sprintf(buf,"%s","kset_name");
        return buf;
}
 
int kset_uevent(struct kset *kset, struct kobject *kobj,struct kobj_uevent_env *env)//���û��ռ䴫 �������¼�  ������
{
        int i = 0;
        printk("uevent: kobj %s.\n",kobj->name);

        while( i < env->envp_idx){
                printk("%s.\n",env->envp[i]);
                i++;
        }

        return 0;
}

struct kset_uevent_ops uevent_ops =//���ڴ����Ȳ���¼�
{
	.filter = kset_filter,
	.name = kset_name,
	.uevent = kset_uevent,
};

struct kset kset_dong1;
struct kset kset_dong2;
int kset_test_init()
{
	printk("kset test init.\n");
	kobject_set_name(&kset_dong1.kobj,"dong1");//�� /sys/ Ŀ¼�´���һ����Ŀ¼ dong1
	kset_dong1.uevent_ops = &uevent_ops;
	kset_register(&kset_dong1);//ע��kset

	kobject_set_name(&kset_dong2.kobj,"dong2");//����һ��Ŀ¼
	kset_dong2.kobj.kset //ָ���ոմ�����Ŀ¼(kobject)  �ĸ�Ŀ¼ kset (kset_dong1)
	= &kset_dong1;
	kset_register(&kset_dong2);
	return 0;
}

void kset_test_exit()
{
        printk("kset test exit.\n");
        kset_unregister(&kset_dong1);
        kset_unregister(&kset_dong2);
}

module_init(kset_test_init);
module_exit(kset_test_exit);


 
