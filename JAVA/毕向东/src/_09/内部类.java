package _09;
/*
 * �ڲ�����ʹ���
 * 1���ڲ������ֱ�ӷ����ⲿ���еĳ�Ա������˽��
 * 		֮���Կ���ֱ�ӷ����ⲿ���еĳ�Ա������Ϊ�ڲ����г�����һ���ⲿ������ã���ʽ���ⲿ����.this
 * 2���ⲿ������ڲ��࣬���뽨���ڲ������
 */
class Other{
	private int x =3;
	
	class Inner{
		void method(){
			System.out.println(x);//�����ⲿ��Ա
		}
		void show(){
			System.out.println("�ڲ���");
		}
	}
	
	void method(){
		Inner i = new Inner();//�����ڲ���
		i.method();
	}
}
class Other2{
	private int x =1;
	
	class Inner{
		int x = 2;					//���ڲ����� ���������ⲿ��  һ��ʱ
		void method(){
			int x = 3;
			System.out.println(x);
			System.out.println(this.x);
			System.out.println(Other2.this.x);
		}
	}
}

public class �ڲ��� {
	public static void main(String[] args) {
		new Other().method();
		
		Other.Inner i = new Other().new Inner();//�����ڲ������ĸ�ʽ
		i.show();
		
		System.out.println();
		new Other2().new Inner().method();
	}
}
