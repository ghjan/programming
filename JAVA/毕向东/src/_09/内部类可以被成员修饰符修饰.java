package _09;
/*
 * 2�����ڲ����ڳ�Աλ���ϣ��Ϳ��Ա���Ա���η�������
 *    ���磺private�����ڲ������ڵ��ⲿ���н��з�װ
 *    	   static���ڲ���;߱�static������
 *    		���ڲ��౻static���κ�ֻ��ֱ�ӷ����ⲿ���е�static��Ա
 *    
 *    ���ⲿ�������з���static�ڲ���ķǾ�̬��Ա��new Other3.Inner().method();		// ��Ҫ new һ��Inner�Ķ���
 *    ���ⲿ�������з���static�ڲ���ľ�̬��Ա	     ��Other3.Inner.show();				//����Ҫnew ���󡣡�ֱ�ӵ��þ�̬����
 *    
 *    ע�⣺���ڲ��ඨ���˾�̬��Ա�����ڲ��������static
 */
class Other3{
	private static int x =3;
	
	static class Inner{
		void method(){
			System.out.println(x);//�����ⲿ��Ա
		}
		static void show(){
			System.out.println("�ڲ���");
		}
	}
}
public class �ڲ�����Ա���Ա���η����� {
	public static void main(String[] args) {
		new Other3.Inner().method();
		Other3.Inner.show();
	}
}
