package _06;

/**
 * ע���ӡ������˳��
 */
class StaticCode1{
	int num = 10;
	//��̬����飬�����ʼ������ע�⣺���Ҫ���� ����  ��ֻ�ܵ��þ�̬����
	static{
		System.out.println("a");
	}
	//�������飬�������ʼ����
	{
		System.out.println("b"+this.num);
	}
	//���캯��������Ӧ�����ʼ����
	StaticCode1(int x){
		System.out.println("c");
	}
}
public class ��̬�����2 {
	public static void main(String[] args) {
		new StaticCode1(4);
	}
}

