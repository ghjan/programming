package _07;

public class �Ӹ��������ص� {
	public static void main(String[] args) {
		Zi z = new Zi();
		//�������п��Ե��ø��������
		System.out.println(z.s1);
		System.out.println(z.s2);
		z.show();
	}
}

class Fu{
	String s1 = "����";
	int age = 20;
}

class Zi extends Fu{
	String s2 = "����";
	int age = 10;
	public void show(){
		System.out.println(super.age+"  "+age);
	}
}