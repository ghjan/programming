package _20;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.SequenceInputStream;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.Vector;

public class IO_11_�и��ļ� {
	public static void main(String[] args) throws IOException {
		splitFile();
		hebing();
	}
	
	public static void splitFile() throws IOException{
		FileInputStream fis = new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��.jpg");
		FileOutputStream fos = null;
		
		byte[] buf = new byte[1024*100];//ÿ��100kb
		int len = 0;
		int count = 1;
		while((len = fis.read(buf))!= -1 ){
			fos = new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\��"+(count++)+".part");
			fos.write(buf,0,len);
			fos.close();
		}
		fis.close();
	}
	//��ArrayList���ϲ�
	public static void hebing() throws IOException{
		ArrayList<FileInputStream> al = new ArrayList<FileInputStream>();
		for(int i=1;i<5;i++){
			al.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��"+i+".part"));
		}
		
		final Iterator<FileInputStream> it = al.iterator();//��ȡ������
		//ΪʲôҪ������һ������Ϊ��SequenceInputStream(Enumeration<? extends InputStream> e) ֻ����Enumeration�ӿڷ���
		Enumeration<FileInputStream> en = new Enumeration<FileInputStream>(){//����һ���ڲ���    Ȼ��д�ӿڷ���
			public boolean hasMoreElements() {
				return it.hasNext();
			}
			public FileInputStream nextElement() {
				return it.next();
			}
		};
		
		SequenceInputStream sis = new SequenceInputStream(en);
		
		File f = new File("E:\\programming\\JAVA\\�����ļ�\\��5.jpg");
		FileOutputStream fos = new FileOutputStream(f);
		
		byte[] buf = new byte[1024];
		int len = 0;
		while((len = sis.read(buf))!=-1){
			fos.write(buf,0,len);
		}
		fos.close();
		sis.close();
//		Vector<FileInputStream> v = new Vector<FileInputStream>();
//		v.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��1.part"));
//		v.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��2.part"));
//		v.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��3.part"));
//		v.add(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\��4.part"));
//		
//		Enumeration<FileInputStream> en = v.elements();
//		//SequenceInputStream ��ʾ�������������߼����������������������򼯺Ͽ�ʼ�����ӵ�һ����������ʼ��ȡ��ֱ�������ļ�ĩβ��
//		//���Ŵӵڶ�����������ȡ���������ƣ�ֱ��������������һ�����������ļ�ĩβΪֹ�� 
//		SequenceInputStream sis = new SequenceInputStream(en);
//		
//		FileOutputStream fos = new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\��5.bmp");
//		
//		byte[] buf = new byte[1024*100];
//		int len = 0;
//		while((len = sis.read(buf))!=-1){
//			fos.write(buf,0,len);
//		}
//		fos.close();
//		sis.close();
	}
}
