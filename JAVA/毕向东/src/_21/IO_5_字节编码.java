package _21;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;

/*
 * ���룺�ַ�������ֽ�����
 * 
 * ���룺�ֽ��������ַ���
 * 
 */
public class IO_5_�ֽڱ��� {
	public static void main1(String[] args) throws Exception {
		String s = "���";
		
		byte[] b1 = s.getBytes("GBK");//����
		byte[] b2 = s.getBytes("UTF-8");//����
		System.out.println(Arrays.toString(b1));//4���ֽ�
		System.out.println(Arrays.toString(b2));//6���ֽ�
		
		String s1 = new String(b1,"GBK");//��ȷ����
		System.out.println(s1);
		
		s1 = new String(b1,"UTF-8");//�������
		System.out.println(s1);
		
		s1 = new String(b2,"GBK");//�������
		System.out.println(s1);
	}
	public static void main(String[] args) throws IOException {
		String s = "���";
			
		byte[] b1 = s.getBytes("GBK");//����

		//��������ʾ�����������֮�󣬻��ܷ�ͨ���ٴα��룬������ȷ����
		System.out.println("��ȷ�����ֽڸ�����"+Arrays.toString(b1));
		
		String s2 = new String(b1,"iso8859-1");//�������
		System.out.println("so8859-1���룺"+s2);
		
//		byte[] b3 = s2.getBytes("iso8859-1");//�ٴα��루������ŷ��ʹ�õ����ԣ�
//		System.out.println("��������ֽڸ���"+Arrays.toString(b3));
		byte[] b3 = s.getBytes("UTF-8");//�������
		System.out.println("��������ֽڸ�����"+Arrays.toString(b3));
		String s3 = new String(b3,"gbk");//��������gbk  �������ڿ�ʼ����������Ե�����������󣬣����������ʼ��iso8859-1����Ͳ��������
		System.out.println("���룺"+s3);													//ԭ������UTF-8��gbk��ʶ�����ģ�iso8859-1��ʶ������
	}
}
