package _18;

import java.io.FileWriter;
import java.io.IOException;

public class IO_3_�ļ���д {
	public static void main(String[] args) throws IOException {
		FileWriter fw = new FileWriter("E:\\programming\\JAVA\\�����ļ�\\io_1.txt",true);//����һ��true������׷�ӵķ�ʽд�롣�����´����ļ�
		fw.write("\r\n1234");
		fw.write("\r\n1234");
		fw.write("\r\n1234");
		fw.write("\r\n1234");
		fw.close();
		
	}
}
