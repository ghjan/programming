package ��;

// static�����������еı����򷽷�����Ϊ��̬��������̬����
// ��̬�����������е��������ͬһ���ڴ�ռ�
// 
public class ��ʽ����ת�� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat myCat = new Cat();		
		Cat.testClass();
		Animal.testClass();
		System.out.println( );
		//Cat.testInstance();	//Cat ֻ�ܵ��������� static �ķ���
		myCat.testClass();		// Cat �Ķ�����Ե��� ���е�һ��
		myCat.testInstance();
		
		System.out.println( );
		
		Animal myAnimal = myCat;
		Animal.testClass();//Animal ֻ�ܵ��� ������static �ķ���
		//��������Կ���  ֻ����ʽ����ת����  �����е� static ����  
		// static ���ڳ���ִ��ʱ,����ֽ����ļ��ͼ��ص��ڴ���ȥ��
		// û�� static �Ͳ��ܼ��ص��ڴ���ȥ����Ҫ����������м���
		myAnimal.testClass();//������Կ��������˸����   	�෽��
		// ������д�ĵط�   ����ת�������������û����д�Ϳ�����ȫת��ΪAnimal��
		myAnimal.testInstance();
		
		System.out.println( );
		
		Animal mytest = new Animal();
		mytest.testClass();
		mytest.testInstance();
	}
}
//����һ�� ����
class Animal{
	public static void testClass(){//�����static����  ֻ�ܸ����Լ��ã����������෽�����ı�
		System.out.println("Animal�е��෽��");
	}
	public void testInstance(){	// �����������������ʱ������ķ���Ҳ��ı�
		System.out.println("Animal�е�ʵ������");
	}
}
//����һ������
class Cat extends Animal{
	public static void testClass(){//�������ǶԸ������д�����������ʲ�������static�ķ���
	System.out.println("Cat ����ķ���");
	}
	// �����������   ����               �������д
	public void testInstance(){
		System.out.println("Cat�����ʵ������");
	}
}
