package _09;
/*
 * �ں����������쳣
 * �Ա�����߰�ȫ�ԣ��ڱ���ʱ ��ʾ  �쳣  ���д������������ʧ��
 */
class div1{
	int div(int a,int b)throws Exception  	//�ڹ�����ͨ��throws�ؼ��������ù��ܿ��ܻ��������
	{
		return a/b;
	}
}

public class �쳣2 {
	public static void main(String[] args)/*throws Exception*/{		//������  �� throws Exception��ע�͵��ĵط�������������������
		System.out.println("start");
		int x;
		try {														//��õ��ǽ��д���     �ã�try{} catch{}���д���
			x = new div1().div(10,0);
			System.out.println("x == "+x);
		} catch (Exception e) {
			System.out.println(e.toString());
		}
		
		System.out.println("over");
	}
}
