package _19;

import java.io.IOException;
import java.io.PrintStream;
import java.text.SimpleDateFormat;
import java.util.Date;

public class IO_7_�쳣��־ {
	public static void main(String[] args)throws IOException {
		try {
			int [] arr = new int[2];
			System.out.println(arr[3]);
		} catch (Exception e) {
			try {
				Date d = new Date();
				SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
				String s = sdf.format(d);
				
				PrintStream ps = new PrintStream("E:\\programming\\JAVA\\�����ļ�\\io_2.txt");
				ps.println(s);
				System.setOut(ps);
			} catch (Exception e2) {
				// TODO: handle exception
				throw new RuntimeException("��־�ļ�����ʧ��");
			}
			e.printStackTrace(System.out);
			
		}
		
		
	}
}
