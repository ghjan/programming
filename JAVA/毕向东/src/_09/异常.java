package _09;
/*
 * �쳣����������ʵ����java�Բ������������������Ķ������֡�
 * 
 * ������Ļ��֣�һ�������ص����⣬һ���Ƿǳ����ص�����
 * 
 * �������صģ�javaͨ��error���������
 * 		����error һ�㲻��д����ԵĴ�����䴦��
 * 
 * ���ڷǳ����صģ�javaͨ��exception���������
 * 		����exception����ʹ������ԵĴ���ʽ���д���
 * 
 * ����error����exception������һЩ��������
 * ���磺�������������Ϣ������ԭ���
 * 
 * Throwable
 * 		|--Error
 * 		|--Exception
 * 
 * 
 * 2���쳣�Ĵ���
 * java�ṩ�����е������д���
 * try
 * {
 * 		��Ҫ������Ĵ���
 * }
 * catch(�쳣��  ����)
 * {
 * 		�����쳣�Ĵ��룺������ʽ��
 * }
 * finally
 * {
 * 		һ����ִ�е����
 * }
 * 3���Բ��񵽵��쳣������г�����������
 * 		String
 */
class div{
	int div(int a,int b){
		return a/b;
	}
}
public class �쳣 {
	public static void main(String[] args) {
		try {
			System.out.println("start");
			int x = new div().div(10,0);
			System.out.println("x == "+x);
		} catch (Exception e) {				//���൱��Exception e = new ArithmeticException();������һ����̬
			System.out.println("����0��");
			System.out.println(e.getMessage());
			System.out.println(e.toString());//�쳣���ƣ��쳣��Ϣ
			e.printStackTrace();//�쳣���ƣ��쳣��Ϣ���쳣���ֵ�λ��
			//��ʵjvmĬ�ϵ��쳣������ƣ������ڵ��� printStackTrace();����
			//��ӡ�쳣�Ķ�ջ�ĸ�����Ϣ
		}
		
		System.out.println("over");
	}
}
/*
 * String getMessage() 
          ���ش� throwable ����ϸ��Ϣ�ַ����� 
          
   String toString() 
          ���ش� throwable �ļ�������� 
          
   StackTraceElement[] getStackTrace() 
          �ṩ��̷����� printStackTrace() ����Ķ�ջ������Ϣ�� 
*/
