package _06;
/**
 * ��̬�����
 * ��ʽ��
 * static
 * {
 * 		��̬������е�ִ�����
 * }
 * �ص㣺������ļ��ض�ִ�У�ִֻ��һ��
 * ���ڸ����ʼ����
 */
class StaticCode{
	public static void show(){
		System.out.println("haha");
	}
	
	static{
		System.out.println("c");
	}
}
public class ��̬����� {
	static{
		System.out.println("a");
	}
	
	public static void main(String[] args) {
//		new StaticCode();
//		new StaticCode();//���� new StaticCode    ���� static�����ִֻ��һ��
//		System.out.println("over");
		
		StaticCode.show();//���÷���ʱҲ�Զ����� static�����
		
	}
	
	static{
		System.out.println("b");
	}
	
}
