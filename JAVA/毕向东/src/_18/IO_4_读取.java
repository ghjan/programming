package _18;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class IO_4_��ȡ {
	public static void main(String[] args) throws IOException {
		//Ҫ��֤�ļ�����
		FileReader fr = new FileReader("E:\\programming\\JAVA\\�����ļ�\\io_1.txt");
		//���ö�ȡ�������read������read()һ����һ���ַ������һ��Զ����¶�������ĩβ����-1
		//��һ�� ��ʽ
//		int ch;
//		while((ch = fr.read())!=-1)
//			System.out.println((char)ch);
		
		//�ڶ���
		//����һ���ַ����飬���ڴ洢�������ַ�
		char[] buf = new char[1024];
		int num;
		while((num = fr.read(buf))!=-1){
			System.out.print(new String(buf,0,num));
		}
		
	}
}
