package _19;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/*
 * ͨ��������
 * 
 */
public class IO_4_����mp3 {
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		copy();
		long end = System.currentTimeMillis();
		System.out.println("����"+(end-start)+"����");
		
	}
	public static void copy() throws IOException {
		BufferedInputStream bufis = new BufferedInputStream(new FileInputStream("D:\\����\\Cincinnati Pops Orchestra - Themes from Silverado.mp3"));
		BufferedOutputStream bufos = new BufferedOutputStream(new FileOutputStream("C:\\Users\\37916\\Desktop\\1.mp4"));
		
		int Byte = 0;
		while((Byte = bufis.read())!= -1){//ע�������Ƕ�ȡһ���ֽڣ����ص�������ֽڡ���ת��Ϊ10����   ��  ����   0xff  ����������
			bufos.write(Byte);//ע��������дһ���ֽڡ�ֻ��Byte���ʮ���Ƶ�  ��8λ����ʮ����ǿתΪbyte������ʵ������������Ҳֻ�е�8λ��Ч������λȫΪ0
		}
		//ΪʲôҪ����ת��Ϊ10���ƣ�Ȼ����ת��Ϊbyte�ͣ�
		//��Ϊ���н�����������������-1   ��ô���п��ܴ�����������(������)����11111111  ��ô�Ͳ������𣬵����ĸ��ǽ�����
		//Ҳ����˵   ����ͽ�������ͻ����Ϊ����11111111���ֶ��������ݿ��Խ��д���
		bufis.close();
		bufos.close();
	}
}
