package �ַ�;

public class StringBuffer�� {
	public static void main(String [] args){
		//����һ��StringBuffer ���� sb 
		StringBuffer sb = new StringBuffer();
		
		//append ��һ������  ����Ӳ�����  StringBuffer ������ 
		sb.append("�Һ�");
		sb.append("����");
		sb.append("dong");
		
		// toString ��һ������  ������һ��������StringBuffer�е��ַ����У�
		System.out.println(sb.toString());
		// ������һ��  ��Ҫ toString Ҳ�������
		System.out.println(sb);
	}
}
// StringBuffer �� String �ıȽ�

/* StringBuffer �в����Ķ���  Ĭ����16 ���ַ��ĳ��� �����ݺͳ��ȶ����Ըı䣬�������Գ��������������������ԣ���String�ǹ̶��ģ�*/
