package _09;
/*
 * �Զ��쳣�Ĵ���
 * 
 * 1�������쳣ʱ������������Ϊ������쳣�������������Ը��Ӿ���
 * 2���Է����������쳣���Ͷ�Ӧ����catch �顣��Ҫ��������catch��
 * 		������catch���е��쳣���ּ̳й�ϵ�������쳣catch�����������
 * 
 * �����ڽ���catch ����ʱ��catch��һ��Ҫ�������Ĵ���ʽ
 * ��Ҫ�򵥶���һ�䣺e.printStackTrace()
 * Ҳ��Ҫ�򵥵ľ���дһ��������
 */
class Demo{
	int div(int a,int b)throws ArithmeticException,ArrayIndexOutOfBoundsException
	{
		int[] arr = new int [a];
		System.out.println(arr[4]);//����Խ��ʼ����  ����0 ֮ǰ�����������ͬʱ����  ֻ�ܴ��������쳣��Ȼ����γ���Ͳ�ִ����
		return a/b;
	}
}
public class �쳣3 {
	public static void main(String[] args) {
		Demo d = new Demo();
		try {
			int x = d.div(5, 1);//��5��Ϊ4   ���߰� 0��Ϊ1
		} catch (ArithmeticException e) {
			System.out.println(e.toString());
			System.out.println("����0 ��");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println(e.toString());
			System.out.println("����Խ����");
		}/*
		catch(Exception e){							//��������ô����������  �Ͳ���    ��������ԵĴ������⡣��excepton�Ǹ��ࣩ
			System.out.println(e.toString());		//�����Ҫ���ϣ�Ҳ��Ҫ����  ArithmeticException  ArrayIndexOutOfBoundsException  ֮ǰ
		}*/											//�������ᵼ��  ��� ǰ�������쳣��  ������   ��ȫ��������Զִ�в�������
		System.out.println("over");
	}
}
//Arithmetic  ����    Exception  �쳣������
//ArrayIndexOutOfBoundsException����Խ���쳣
