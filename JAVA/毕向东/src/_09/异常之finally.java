package _09;

public class �쳣֮finally {
	public static void main(String[] args) {
		int x;
		try {
			x = new div1().div(10,0);
			System.out.println("x == "+x);
		} catch (Exception e) {
			System.out.println("�����쳣");
		} finally {
			System.out.println("finally");//һ��ִ�еĴ���
		}

		System.out.println("over");
	}
}
