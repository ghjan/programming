package �ӿ�;

//����ӿ�A

//�ӿھ�����c�����е�.hͷ�ļ��е�  ��������
interface InterfaceA{
	final int sum1 = 20;//final �����ĵı���ֻ�ܱ���ֵһ�Σ��ڶ��θ�ֵ�����
	int getValue();
}
//����ӿ�B
interface InterfaceB{
	void say();
}
//�����࣬��ʵ�ֽӿ�
class InterfaceTest implements InterfaceA,InterfaceB{
	public int getValue(){
		System.out.println("ʵ�ֽӿ�A\tgetValue�ķ���");
		return 0;
	}
	public void say(){
		System.out.println("ʵ�ֽӿ�B\t��say����");
	}
	
}

public class �ӿڵ�ʵ�� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InterfaceTest obj = new InterfaceTest();
		obj.getValue();
		obj.say();
	}

}
