package _09;
/*
 * �ڲ��ඨ���ھֲ�ʱ
 * 1�������Ա���Ա���η�����
 * 2������ֱ�ӷ����ⲿ���еĵĳ�Ա����Ϊ�������ⲿ���е�����
 * 		���ǲ����Է��������ڵľֲ��еı�����ֻ�ܷ��ʱ�final���εľֲ�����
 */
class Outer{
	int x = 3;
	void method(final int a){
		final int y = 4;
		class Inner{//�����û�з��ڳ�Աλ���ϣ����Բ��ܱ���Ա���η�������
			void function(){
				System.out.println(x);
				System.out.println(y);//Ҫ����� y  ����y ��ʱ��������final
				System.out.println(a);
			}
		}
		//���������Inner�Ķ�����ôfunction�Ͳ���ִ��
		new Inner().function();
	}
	
}
public class �ڲ�����ھֲ�ʱ {
	public static void main(String[] args) {
		Outer out = new Outer();
		out.method(10);
		out.method(20);
		
	}
}
