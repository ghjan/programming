package _09;

interface Inter{
	void method();
}
/*		�����һ���⣬��������� Test.function().method();		��ȫ����			*/
public class �����ڲ���2 {
	public static void main(String[] args) {
		
		Test.function().method();	//   ��Ҫ����Ϊ�������仰
		
		/*��仰���Բ�ֳ�     
		 * Inter in = Test.function();
		 * in.method();					�������仰
		 */
	}
}
class Test{
	static Inter function(){	//����һ����̬����
		return new Inter(){		//���ﷵ�ص���һ��    Inter  �� �������ࡣ��һ������
			public void method(){//���������еķ���
				System.out.println("method run");
			}
		};
	}
}

