package _20;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
/*
 * PrintStream
 * ���캯�����Խ��ܵ�����
 * File ����
 * �ַ���·��
 * �ֽ������OutputStream
 * 
 * PrintWriter
 * File ����
 * �ַ���·��
 * �ֽ������OutputStream
 * �ַ������ͨWriter 
 */
public class IO_9_PrintWriter {
	public static void main(String[] args) throws IOException {
		BufferedReader bufr = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out,true);//true������ȼ��������    out.flush();   ÿ����һ�о���ջ�����
//		PrintWriter out = new PrintWriter("E:\\programming\\JAVA\\�����ļ�\\1.txt");
		PrintWriter out = new PrintWriter(new FileWriter("E:\\programming\\JAVA\\�����ļ�\\1.txt"));
		
		String line;
		while((line = bufr.readLine())!=null){
			out.println(line);
//			out.flush();
		}
		
		bufr.close();
		out.close();
		
	}
}
