package _09;

/*ǰ�涨��� ��
 * interface Inter{
	void method();
}*/

public class �����ڲ���3 {
	public static void main(String[] args) {
		
		show(new Inter(){							//����ȥһ�������ڲ���
			public void method(){
				System.out.println("���������ڲ���");
			}
		});
	}
	
	static void show(Inter in){
		in.method();
	}
	
}
