package ��;

class C{
	C(){
		System.out.println("C��Ĺ��췽��");
	}
}
class D extends C{
	D(){
		super();//��һ��ע�͵�Ҳ���ԣ�JAVA���Զ�����Ը���C�ġ����޲Ρ�������
		System.out.println("D��Ĺ��췽��");
	}
}

public class ʹ��super���ø�����޲ι��췽�� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		D d = new D();
		System.out.println( );
//		C c = new C();
	}

}
