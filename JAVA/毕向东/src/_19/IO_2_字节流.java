package _19;
/*
 * �ֽ���
 * InputStream��   OutputStreamд
 * 
 */
import java.io.*;
public class IO_2_�ֽ��� {
	public static void main(String[] args) throws IOException {
		writeFile();
		readFile();
	}
	public static void writeFile() throws IOException{
		FileOutputStream fos = new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\io_1.txt");
		
		fos.write("abcd".getBytes());
		fos.write("2134".getBytes());//����׷�ӵķ�ʽд��
	}
	public static void readFile() throws IOException{
		FileInputStream fis = new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\io_1.txt");
		
		byte[] buf = new byte[1024];
		int len = 0;
		while((len = fis.read(buf))!=-1){
			System.out.println(new String(buf,0,len));
		}
		fis.close();
	}
	
}
