package _09;
/*
 * Exception����һ������������쳣RuntimeException  ����ʱ�쳣
 * 
 * ����ں������׳����쳣�������Ͽ��Բ�������
 * 
 * ����ں����������˸��쳣�������߿��Բ��ý��д���try  ����    ��   ��
 * 
 * ֮���Բ����ں�������������Ϊ����Ҫ�õ����ߴ���
 * �����쳣������ϣ������ֹͣ����Ϊ������ʱ���������޷���������������ϣ��������ֹ
 * Ȼ�����ǶԴ�������޸�
 * 
 * �Զ����쳣ʱ��������쳣�ķ������޷��ټ����������㣬
 * �����Զ����쳣�̳�RuntimeException�쳣 
 * 
 * 
 * �����쳣�����֣�
 * 1������ʱ�������쳣
 * 2������ʱ���������쳣�������쳣��RuntimeException�Լ��������ࣩ
 * 
 * ʲôʱ���׳�RuntimeException�쳣��
 * ����������쳣����������Ͳ������С���ʱ��RuntimeException
 * ����쳣�׳�  1�������ں�����������2������������
 */
class FuShuException2 extends RuntimeException{			//�Զ����쳣����̳�  Exception ����  Throwable  ���� Error
	FuShuException2(String msg){
		super(msg);
	}
}
class Demo2{
	int div(int a,int b)//throws ArithmeticException,ArrayIndexOutOfBoundsException   ���ü�
	{
		if(b<0){
			throw new FuShuException2("���ָ�����");
		}
		if(b==0){
			throw new ArithmeticException("���� 0 ��");
		}
		return a/b;
	}
}
public class RuntimeException�쳣 {
	public static void main(String[] args) {
		int x = new Demo2().div(10,-1);
		System.out.println("x == "+x);
		System.out.println("over");
	}
}
/**
 * ���췽��ժҪ 
ArithmeticException() 
          ���첻����ϸ��Ϣ�� ArithmeticException�� 
ArithmeticException(String s) 
          �������ָ����ϸ��Ϣ�� ArithmeticException�� 
 */
