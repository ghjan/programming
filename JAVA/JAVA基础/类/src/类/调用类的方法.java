package ��;

class Hello{
	void sayHello(){
		System.out.println("hello dong");
	}
}

class Hello1{
	static void sayHello(){
		System.out.println("hello dong");
	}
}

//����ǳ�����
abstract class Hello2{
	static void say(){
		System.out.println("this is a abstract class");
	}
}

public class ������ķ��� {
	public static void main(String [] args){
		//  ������   �ٵ���
		Hello dong = new Hello();
		dong.sayHello();
		
		Hello1.sayHello();
		
		// ����ͨ����������  �����侲̬����
		Hello2.say();
	}
}
