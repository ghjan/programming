package _09;
/*
 * java�����������ø���Ĺ��캯��.���û����super()��ȷָ���Ļ�,Ĭ�ϵ���û�в������Ǹ����캯��
 */
class Fu{
	Fu(String a){
		System.out.println("fu  "+a);
	}
}
class Fu2{
	Fu2(){
		System.out.println("fu2");
	}
}

class Zi extends Fu{
	Zi(){
		super("dong");
		System.out.println("zi");
		//super("dong");			//�����ܷ�����
	}
}
class Zi2 extends Fu2{
	Zi2(){
		System.out.println("zi2");
	}
}
public class ��ϰ��_�̳��еĿղι�����{
	public static void main(String[] args) {
		new Zi();
		new Zi2();
	}
}
