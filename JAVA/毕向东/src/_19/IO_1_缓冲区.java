package _19;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class IO_1_������ {
	public static void main(String[] args) throws IOException {
		//����һ���ַ�д����  ����
		FileReader fr = new FileReader("E:\\programming\\JAVA\\�����ļ�\\io_1.txt");
		FileWriter fw = new FileWriter("E:\\programming\\JAVA\\�����ļ�\\io_2.txt");
		
		//��������Ϊ�������ݸ��������Ĺ��캯��
		BufferedWriter bufw = new BufferedWriter(fw);
		//��ȡ
		BufferedReader bufr = new BufferedReader(fr);
		
		
		String line = null;
		while((line = bufr.readLine())!=null){//�����������ݵ��ַ������������κ�����ֹ��������ѵ�����ĩβ���򷵻� null 
			bufw.write(line);
			bufw.newLine();
			bufw.flush();	
		}
		
	}
}
