package �ӿ�;

public class �ӿ� {
	public static void main(String[] args) {
		new Dilei().fly();
		new Dilei().run();
		new Plane().fly();
		new Plane().run();
}
	
}

interface Aa{
	void fly();
	void run();
}

class Dilei implements Aa{

	@Override
	public void fly() {
		// TODO Auto-generated method stub
		System.out.println("���ײ����");
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println("���ײ�����");
	}
	
}
class Plane implements Aa{

	@Override
	public void fly() {
		// TODO Auto-generated method stub
		System.out.println("�ɻ����");
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println("�ɻ�����");
	}
	
}