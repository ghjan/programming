package _08;

class Dog extends Animal{
	void eat(){
		System.out.println("���Թ�ͷ");
	}
	void Watchdog(){
		System.out.println("������");
	}
}

public class ��̬2 {
	public static void main(String[] args) {
		
		function(new Cat());
		function(new Dog());
	}
	
	public static void function(Animal a){
		a.eat();
		if(a instanceof Cat){//�����è
			((Cat) a).catchMouse();
		}
		else if(a instanceof Dog){//����ǹ�
			((Dog) a).Watchdog();
		}
	}
}
