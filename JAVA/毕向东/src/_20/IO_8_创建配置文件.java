package _20;

import java.io.*;
import java.util.*;

public class IO_8_���������ļ� {
	public static void main(String[] args) throws IOException {
		File file = new File("E:\\programming\\JAVA\\�����ļ�\\count.ini");
		Properties prop = new Properties();
		
		if(!file.exists())//����ļ�������
			file.createNewFile();
		
		FileReader fr = new FileReader(file);
		
		prop.load(fr);//���򵥵������еĸ�ʽ�������ַ����ж�ȡ�����б�����Ԫ�ضԣ���     ��  ����  ����ȡ��ǰ�����ݣ���
		
		int count = 0;
		String value = prop.getProperty("time");//��ȡtime����ֵ����value
		
		if(value!=null){
			//static int parseInt(String s, int radix)ʹ�õڶ�������ָ���Ļ��������ַ�����������Ϊ�з��ŵ�������  
	         count = Integer.parseInt(value);
	         if(count>4){
	        	 System.out.println("��������ʹ�õĴ�������");
	        	 System.exit(0);
	         }
		}
		System.out.println("��ӭʹ��");
		count ++;
		prop.setProperty("time", count+"");
		
		FileWriter fw = new FileWriter(file);
		
		prop.store(fw, "Welcome to My init");//�Ѽ�ֵ��д���ļ���(����)
		
		fw.close();
		fr.close();
	}
}
