package �ַ�;

public class �ַ������ַ����� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char [] helloArray = {'h' , 'e' , 'l' , 'l' , 'o'};	//����һ������
		String helloString = new String(helloArray);		// ���� new String ת��Ϊ�ַ���
		System.out.println(helloString);
		
		
		char [] hello = helloString.toCharArray();		// ���� toCharArray()�������   ��  helloString ����ַ���ת��Ϊ hello ����ַ�����
		for(int i=0;i<hello.length;i++){
			System.out.println(hello[i]);
		}
	}

}
