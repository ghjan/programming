package _20;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.SequenceInputStream;
import java.util.Enumeration;
import java.util.Vector;

public class IO_10_�ϲ��� {
	public static void main(String[] args) throws IOException {
		Vector<FileInputStream> v = new Vector<FileInputStream>();
		v.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��1.part"));
		v.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��2.part"));
		v.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��3.part"));
		v.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��4.part"));
		
		Enumeration<FileInputStream> en = v.elements();
		//SequenceInputStream ��ʾ�������������߼����������������������򼯺Ͽ�ʼ�����ӵ�һ����������ʼ��ȡ��ֱ�������ļ�ĩβ��
		//���Ŵӵڶ�����������ȡ���������ƣ�ֱ��������������һ�����������ļ�ĩβΪֹ�� 
		SequenceInputStream sis = new SequenceInputStream(en);
		
		FileOutputStream fos = new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\��5.bmp");
		
		byte[] buf = new byte[1024*100];
		int len = 0;
		while((len = sis.read(buf))!=-1){
			fos.write(buf,0,len);
		}
		fos.close();
		sis.close();
	}
}
