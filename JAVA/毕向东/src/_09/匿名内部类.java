package _09;
/*
 * 1�������ڲ�����ʵ�����ڲ���ļ�д��ʽ
 * 2�����������ڲ�������Ǽ̳�һ�������ʵ�ֽӿ�
 * 3�������ڲ����ʽ��new ������߽ӿ�{�������������}
 * 4����ʵ�����ڲ������һ����������󣬶�����������е��֡��������Ϊ�����ݵĶ���
 * 5�������ڲ����ж���ķ�����ò�Ҫ����3��
 */
/*
class Outer1{
	class Inner{
		void show(){
			System.out.println("�����ڲ���");
		}
	}
	public void function(){
		new Inner().show();
	}
}
public class �����ڲ��� {
	public static void main(String[] args) {
		new Outer1().function();
	}
}*/
//	�����������������ڲ���    ʵ������Ĵ���
abstract class Abs{
	abstract void show();
}
class Outer1{
	void function(){
		//����������ڲ���
		new Abs(){				//����һ��û�����ֵ��࣬������Ϊû�����֣������õ��Ǹ��������     ��ǧ��Ҫ��Ϊnew����Abs�Ķ��󣬿���Abs�ǳ���ģ�					
			void show(){		//���ڸ�����һ�������࣬�������ʵ�ָ������еķ�������������һ�������ŷ����Ķ��󣨺��ֵĶ���
				System.out.println("�ڲ���");
			}
		}.show();//���󴴽����ˣ���Ӧ�õ��ú�����     ��ǰ�ĵ��þ���   new Inner().show();    �ǲ��ǾͶ���һ���������м�
	}
}
//���������ø���ʵ�ֵ������ڲ��ࡣ�������������ýӿ�ʵ�ֵ��ڲ��ࡣ��������ʵ�����ҿ����ӿ�Ҳ�������һ�֡�
interface In{
	void show();
//	void show1();     һ����������֮����ò��� ��������̫�鷳��
//	void show2();
//	void show3();
}
class Outer2{
	void function(){
		//����new  �˼�������
		new In(){
			public void show(){
				System.out.println("�����ڲ���");
			}
		}.show();
		
		new In(){
			public void show(){}
			void hehe(){
				System.out.println("�Ǻ�");
			}
		}.hehe();
	}
	//�ᷢ�ֵ���������һ��  ��ķ��������÷ǳ��鷳����ƽʱ�����������������ķ������Ƕ�����ʹ����������ġ���������������
	void function2(){
		In i = new In(){					//���Ƕ�̬������������    ָ��    �������
			public void show(){
				System.out.println("����������������");
			}
			void hehe(){}
		};
		i.show();
		//i.hehe();			�������������еķ������ܵ���
	}
}

public class �����ڲ��� {
	public static void main(String[] args) {
		new Outer1().function();
		new Outer2().function();
		new Outer2().function2();
	}
}
