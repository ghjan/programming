package _18;
/*
 * �ַ����������ࣺ
 * InputStream	OutputStream
 * 
 * �ַ����������ࣺ
 * Reader Write
 * 
 * ������Ӳ���ϣ�����һ���ļ�����д��һ������
 * 
 * �ҵ�һ��ר�����ڲ����ļ���Writer�������FileWirter����׺���Ǹ�������ǰ׺���Ƕ���Ĺ���
 */
import java.io.*;
public class IO_1_�ַ���_�ֽ��� {
	public static void main(String[] args) throws IOException {
		//����һ��FileWriter���󡣸ö���һ����ʼ���ͱ�����ȷ���������ļ�
		FileWriter fw = new FileWriter("E:\\programming\\JAVA\\�����ļ�\\io_1.txt");//ע��ӷ�б��
		//void write(String str)  д���ַ�����(д������������
		fw.write("dong");
		//ˢ�¸��������еĻ������е����ݣ�������ˢ��Ŀ�ĵ���
		fw.flush();
		
		fw.write("1234");
		
//		fw.flush();
		fw.close();//�ر�Ҳˢ��
		
		
        
		
	}
}
