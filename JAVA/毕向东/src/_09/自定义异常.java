package _09;
/*
 * ��Ϊ��Ŀ�л�������е�����
 * ����Щ���Ⲣδ��java������������װ����
 * ���Զ�����Щ���е�������԰���java�������װ��˼��
 * �����е����⣬�����Զ�����쳣��װ
 * 
 * �Զ����쳣
 * 
 * �����ڱ������У����ڳ����Ǹ�����Ҳ����Ϊ�Ǵ���ģ����޷����������
 * ��ô����Ҫ�������������Զ��������
 * 
 * 
 * ���ں����ڲ�������throw�׳��쳣������ô�ͱ���Ҫ����Ӧ�Ĵ�����
 * Ҫô���ڲ�try catch����
 * Ҫô�ں����������õ����ߴ���
 * 
 * һ������£������ڳ����쳣����������Ҫ������
 * 
 * ���ִ�ӡ�Ľ����ֻ���쳣�����ƣ�û���쳣����Ϣ
 * ��Ϊ�Զ�����쳣��δ������Ϣ
 * 
 * ����Զ����쳣��Ϣ�أ�
 * ��Ϊ�������Ѿ����쳣��Ϣ�Ĳ�����������
 * ��������ֻҪ�ڹ���ʱ�����쳣��Ϣ��������ͨ��super
 * ��ô�Ϳ���ֱ��ͨ��getMessage������ȡ�Զ�����쳣��Ϣ
 * 
 * �Զ����쳣��
 * �������Զ�����̳�Exception
 * 
 * �̳�Exception��ԭ��
 * �쳣��ϵ��һ���ص㣬��Ϊ�쳣����쳣���󶼱��׳�
 * ���Ƕ��߱������ԣ������������Throwable�����ϵ�ж����ص�
 * 
 * ֻ�������ϵ�е���Ͷ���ſ��Ա�throws��throw����
 * 
 */
class FuShuException extends Exception{			//�Զ����쳣����̳�  Exception ����  Throwable  ���� Error
	private int value;
	
	FuShuException(){
		
	}
	//���������������Զ����쳣  �������쳣��һ�������Ի�ȡ���쳣ʱ�Ǹ�������
	FuShuException(String msg,int value){
		super(msg);
		this.value = value; //��ȡ����
	}
	public int getValue(){//�����Ǹ�����
		return value;
		
	}
}

class Demo1{
	int div(int a,int b)throws FuShuException{
		if(b<0){
			throw new FuShuException("�����˸��������",b);//�ֶ�ͨ�� throw���ؼ��֣��׳�һ���Զ����쳣����  	ע���ǣ�throw  ���� throws
		}
		return a/b;
	}
}

public class �Զ����쳣 {
	public static void main(String[] args) {
		Demo1 d = new Demo1();
		try {
			int x = d.div(5,-10);
			System.out.println("x = "+x);
		} catch (FuShuException e) {						//��������쳣������ִ����һ��
			System.out.println(e.toString());
			System.out.println("����ԭ��"+e.getMessage());
//			if(e.getValue()!=0)
			System.out.println("����ĸ����ǣ�"+e.getValue());
		}
		System.out.println("over");
	}
}
/*������ Throwable ���µ�Դ��
 *class Throwable
 *{
 * 	private String message;
 * 	Throwable(String message)
 * {
 * 	this.message = message;
 * }
 * 
 * public String getMessage()
 * {
 * 	return mesage;				//����ֱ�Ӵ�ӡ   ��������  message ��Ϣ
 * }
 * }
 * 
 * �������๹�캯����ֻҪʹ��   super(msg)	�Ϳ������ø���Ĵ�����
 */

/*
���������Exception��Ĳ���Դ��
public class Exception extends Throwable {

    public Exception() {
        super();																����exceptionҲ��ֱ�Ӽ̳�Throwable��
    }
    public Exception(String message) {
        super(message);															����exceptionҲ��ֱ�Ӽ̳�Throwable��
    }
 */
