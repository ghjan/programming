package ��;

class User{
	public String name ;
	public int age;
	public User(String name,int age){//����һ���������Ĺ��췽��
		this.name = name;
		this.age = age;
	}
}
class Tom extends User{
	public String password;
	public Tom(String name,int age,String passwd){
		super(name,age);
		this.password = passwd;
	}
	void dong(){
		System.out.println(super.name+"\n"+super.age+"\n"+password);
	}
}

public class Super���ø�����ι��췽�� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tom man = new Tom("chen",20,"123456");
		man.dong();
	}

}
