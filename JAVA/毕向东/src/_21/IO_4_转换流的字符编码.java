package _21;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;

public class IO_4_ת�������ַ����� {
	public static void main(String[] args) throws IOException {
		OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\gbk.txt"),"GBK");
		osw.write("���");
		osw.close();
		
		OutputStreamWriter osw2 = new OutputStreamWriter(new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\UTF-8.txt"),"UTF-8");
		osw2.write("���");
		osw2.close();
	}
}
