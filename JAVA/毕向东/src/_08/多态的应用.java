package _08;
/*
 * ������ѧ����
 * 		ѧϰ��˯��
 * �߼����ѧ����
 * 		ѧϰ��˯��
 * 
 * ���Խ�������������г�ȡ
 */
abstract class Student{
	public abstract void study();
	public void sleep(){
		System.out.println("����˯");
	}
}

class DoStudent{
	public void doSome(Student s){
		s.study();
		s.sleep();
	}
}

public class ��̬��Ӧ�� {
	public static void main(String[] args) {
		DoStudent d = new DoStudent();
		d.doSome(new BaseStudent());
		d.doSome(new AdvStudent());
	}
}



class BaseStudent extends Student{
	public void study(){
		System.out.println("base study");
	}
	public void sleep(){
		System.out.println("����˯");
	}
}
class AdvStudent extends Student{
	public void study(){
		System.out.println("adv study");
	}
}