package ��;

class E{
	E(int a){
		System.out.println("C��Ĺ��췽��"+a);
	}
}
//���඼����ø���Ĺ��췽��
class F extends E{
	F(int b){
		super(20);//��һ�в���ע�͵���JAVA���Զ�����Ը���E�ġ����޲Ρ������ã����Ǹ���û���޲ι��췽����
		System.out.println("D��Ĺ��췽��"+b);
	}
}


public class ���ø����в��޲ι��췽�� {
		public static void main(String[] args) {
		// TODO Auto-generated method stub
		F d = new F
				(10);
		System.out.println( );
//		C c = new C();
	}
}
//����Ĺ��������ṩ�Ĳ�������ֻ�����в�����һ���ֵ�ֵ�������ȵ��ø�����޲ι��캯������ܿ�����Щ��Ҫ�Ĳ���û�н��г�ʼ����ֵ��������������������в���ʱ��������صĴ���
//�����б�Ҫ����һ�θ�����޲ι��캯����
