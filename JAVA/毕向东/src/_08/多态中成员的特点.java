package _08;

class Fu{
	int n = 1;
	
	void show1(){
		System.out.println("fu_show1");
	}
	
	static void show2(){				//����static �ڼ������ʱ�򣬺����ƾ�̬�󶨵�
		System.out.println("fu_show2");
	}
	
}
class Zi extends Fu{
	int n = 2;
	
	void show1(){
		System.out.println("zi_show1");
	}
	
	static void show2(){
		System.out.println("zi_show2");
	}
	
}
/* �ڶ�̬�У���Ա�������Ǿ�̬�����ص�
 * ����ʱ����� * ����ʱ���ұ�
 * 
 * �ڶ�̬�У���Ա�������ص�
 * ���۱�������У����ο���ߣ������ͱ����������ࣩ
 * 
 * �ڶ�̬�У���̬��Ա�������ص㣺
 * ���۱�������У����ο����
 */
public class ��̬�г�Ա���ص� {
	public static void main(String[] args) {
		Fu f = new Zi();
		Zi z = new Zi();
		
		//������д����  ����  �Ŀ��㡣���Ƚ���Ҫ
		f.show1();	//���ص�������ķ���*****************************�������Ū��
		System.out.println(f.n);	//���ص��Ǹ���Ķ���
		z.show1();	//���ص�������ķ���
		System.out.println(z.n);	//���ص�������Ķ���
		
		
		//����show2�Ǿ�̬�ģ���һ������֮��ͺ� f ���ˡ����÷���ʱ���ǵ��ø���ķ����������ٿ����Ķ��󣬵��������ĸ���
		f.show2();//*************************************************�������Ū��
		z.show2();
	}
}
