package _23;

public class ���һ��Stringռ�����ֽ� {
	public static void main1(String[] args) {
		String s1 = "ѧjava";//����ռ�����ֽڡ������Ķ�ռһ���ֽ�
		String s2 = "abc";
		String s3 = "3";
		System.out.println(s1.length());
		System.out.println(s2.length());
		System.out.println(s3.length());
		
		byte[] buf = {1,2,8};
		int b = 10;
		buf[0] = (byte) b;
		System.out.println(buf[0]+1);
		System.out.println(buf[1]);
		System.out.println(buf[2]);
		
	}
	public static void main(String[] args) {
//		������˵�����⣬"AAA".getBytes() ����"AAA"��ʵ����ΪString���͵��õģ�����Char
//		����Ե�����һ��char���͵ġ�
		Character  a ='a';//���
		Character  b ='��';
		System.out.println(a.toString().getBytes().length);
		System.out.println(b.toString().getBytes().length);
//		java���л������������ñ�����˵����int��char��bool ��double��short��long��Щ���ǻ���������
//		��Character��Integer���������ñ����������ڽ�����������װ����һ�����������ǿ�����.���㣩�ķ�ʽ���õģ�
//		�����ֵҲ��һ���ġ���̴���ʱ������������Ч�ʸ�Щ������Щʱ��Ҳʹ�����ñ���
	}
}
