package ��̬;

public class ��̬ {
	
	void test(Animal h){
		h.move();
	}
	
	public static void main(String[] args){
		//1
		Animal a = new Human();		//���־ͽж�̬
		a.move();
		//2
		new Human().move();
		//3
		Animal b = new Human();	//����Ҳ�Ƕ�̬
		new ��̬().test(b);
		//4
		new ��̬().test(new Human());// ����Ҳ�Ƕ�̬
		//����4�ֵ�����ʽ
		System.out.println();
		
		new ��̬().test(new Monkey());
		System.out.println( );
		
		Monkey c = new Monkey();
		Animal d = new Animal();
		new ��̬().test(d);
		d.move();
		d = (Animal) c;// ǿ������ת��  �Ѻ��ӵ��ɶ������������ɺ��� 	�����
		d.move();
		
		
	}
}

class Animal{
	void move(){
		System.out.println("��������");
	}
}

class Human extends Animal{
	void move(){
		System.out.println("������");
	}
}

class Monkey extends Animal{
	void move(){
		System.out.println("������");
	}
}
