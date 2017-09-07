package _19;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
/*
 * 1����ȷԴ��Ŀ��
 * 		Դ����������InputStream Reader
 * 		Ŀ�ģ��������OutputStream Reader
 * 2�������������Ƿ��Ǵ��ı�
 * 		�ǣ��ַ���
 * 		���ֽ���
 * 3������ϵ��ȷ������ȷҪʹ���Ǹ�����Ķ���
 * 		ͨ���豸����������
 * 		Դ�豸���ڴ棬Ӳ�̣�����
 * 		Ŀ���豸���ڴ棬���̣�����̨
 * 
 */
public class IO_6_��ȡת���� {
	public static void main(String[] args) throws IOException {
		/*
		//��ȡ����¼�����
		InputStream in = System.in;
		
		OutputStream out = System.out;
		//OutputStreamWriter ���ַ���ͨ���ֽ���������
		OutputStreamWriter osw = new OutputStreamWriter(out);
		
		//InputStreamReader���ֽ���ͨ���ַ���������
		InputStreamReader isr = new InputStreamReader(in);*/
		
		//���漸�仰�����Ա�ø���
		InputStreamReader isr = new InputStreamReader(System.in);
		OutputStreamWriter osw = new OutputStreamWriter(System.out);
		
		//ʹ�û�����
		BufferedReader bufr = new BufferedReader(isr);
		String line = null;
		while((line = bufr.readLine())!=null){
			osw.write(line.toUpperCase()+"\r\n");
			osw.flush();
		}
		bufr.close();
	}
	public static void main1(String[] args) throws IOException {
		//������������д��
		
		//�Ӽ���¼��
//		BufferedReader bufr = new BufferedReader(new InputStreamReader(System.in));
		//���ļ�¼��
		BufferedReader bufr = new BufferedReader(new InputStreamReader(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\io_1.txt")));
		
		
		//���������̨
//		BufferedWriter bufw = new BufferedWriter(new OutputStreamWriter(System.out));
		//������ļ���
//		BufferedWriter bufw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\io_1.txt")));
		
		BufferedWriter bufw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\io_2.txt"),"GBK"));
//		BufferedWriter bufw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\io_3.txt"),"UTF-8"));
		String line;
		while((line=bufr.readLine())!=null){
			bufw.write(line);
			bufw.newLine();
			bufw.flush();
		}
	}
}
