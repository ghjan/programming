package _20;

import java.io.File;

public class IO_1_File {
	public static void main(String[] args) {
		consMethod();
	}
	public static void consMethod(){
		//��1.txt��װ��File���󣬿��԰����еĺ��Գ��ֵ��ļ����ļ��з�װ�ɶ���
	File f = new File("E:\\programming\\JAVA\\�����ļ�\\1.txt");
	
	File f2 = null;
	for(int i=0;i<3;i++)
	f2 = new File("E:\\programming\\JAVA\\�����ļ�",i+".txt");
	
	File d = new File("E:\\programming\\JAVA\\�����ļ�");
	File f3 = new File(d , "1.txt");
	
	System.out.println(f);
	System.out.println(f2);
	System.out.println(f3);
	
	}
}
