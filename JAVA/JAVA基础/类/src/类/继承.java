package ��;
//����һ���˵���
class People{
	String name;
	int age;
	People(String name,int age){
		this.name =name;
		this.age =age;
	}
	public String getName(){
		return name;
	}
	public int getAge(){
		return age;
	}
}
// ���ǻ���Ҫ�����Ա�   ���� �������һ������
class Man extends People{
	public String sex;
	public  Man(String name ,int age,String sex){
		super(name ,age);
		this.sex = sex;
	}
}

public class �̳�{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Man a = new Man("������",20,"��");
		System.out.println(a.getName());
		System.out.println(a.name);
		System.out.println(a.getAge());
		System.out.println(a.age);
		System.out.println(a.sex);
		
	}

}
