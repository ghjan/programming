package ��;

class A{
	public String name = "������";
}
class B extends A{
	public String name = "��СС";
	void say(){
		System.out.println(name);
		System.out.println(super.name);
	}
}

public class ���ظ�����ֶ� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		B b = new B();
		b.say();
	}

}
