package _08;

class Animal{
	void eat(){
		System.out.println("����Է�");
	}
}
class Cat extends Animal{
	void eat(){
		System.out.println("è�Է�");
	}
	void catchMouse(){
		System.out.println("èץ����");
	}
}

public class ��̬ {
	public static void main(String[] args) {
		Animal A = new Cat();//��������������ת��
		A.eat();//������è���Ǿ���è������
		// A.catchMouse()   �����������ˣ���Ȼ��������ֻè���������ǲ���֪����ֻ֪�����Ƕ�����Բ��ܵ���è������
		
		Cat C = (Cat)A;//������֪��������һֻè����Ҫ����è�ķ�������ô���ǿ�����ǿ������ת��	Ҳ����������ת��
		C.catchMouse();
		
		/*����ת������Ҫ��ġ������������Ͳ���
		 *Animal a = new Animal(); 
		 *Cat C = (Cat)a;	a �ı��ʲ���è���Ͳ���ǿתΪè
		 */
		
	}
}
