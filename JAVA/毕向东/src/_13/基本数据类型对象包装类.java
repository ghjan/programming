package _13;
/*
 * byte���ؼ��֣������������ͣ��� Byte���ࣨ�����������ͣ���
 * short						short
 * int							Integer
 * long							long
 * boolean						boolean
 * float						Float
 * double						Double
 * char							Character
 * 
 * ʮ����ת������������
 * toBinaryString();
 * toHexString();
 * toOctalString();
 * 
 * 
 */
public class �����������Ͷ����װ�� {
	public static void main(String[] args) {
		//��ȡ�������͵����ֵ
		//System.out.println(Integer.MAX_VALUE);
		
		//��һ���ַ���ת������
		int n =Integer.parseInt("123");//���ַ���ת��Ϊ����123
		System.out.println(n+3);
		Integer i = new Integer("123");
		int num = i.intValue();
		System.out.println("�ڶ����ַ�ת��Ϊ���ֵķ���"+num);
		
		
		long x = Long.parseLong("123");
		
		System.out.println(Integer.toBinaryString(-6));
		System.out.println(Integer.toHexString(60));
		
		x = Integer.parseInt("3c",16);//��16����  3c   ת��Ϊ10����
		System.out.println(x);
		x = Integer.parseInt("110",2);// 
		System.out.println(x);
	}
}
