package _18;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class IO_5_�����ļ� {
	public static void main(String[] args) {
		FileReader fr = null;
		FileWriter fw = null;
		char[] buf = new char[1];
		int num = 0;
		
		try{
			fr = new FileReader("E:\\programming\\JAVA\\�����ļ�\\io_1.txt");
			fw = new FileWriter("E:\\programming\\JAVA\\�����ļ�\\io_2.txt");
			while((num = fr.read(buf))!=-1){
				fw.write(buf,0,num);
			}
		} catch(IOException e){
			System.out.println("�ļ���ȡ����");
		} finally{
			if(fr!=null)
				try {
					fr.close();
				} catch (IOException e2) {
					System.out.println("�ļ��رմ���");
				}
			if(fw!=null)
				try {
					fw.close();
				} catch (Exception e2) {
					System.out.println("�ļ��رմ���");
				}
		}
	}
}
