package _20;

import java.io.File;
import java.io.IOException;

/*
 * File��
 * 1������
 * 		boolean createNewFile();��ָ��λ�ô����ļ���������ļ��Ѿ����ڣ��򲻴���������false
 * 								���������һ�������������һ�����ʹ����ļ�
 * 2��ɾ��
 * 
 * 3���ж�
 * 		boolean exists();	�ļ��Ƿ����
 * 		isFile();
 * 		isDirection();
 * 		isHidden();	����
 * 4����ȡ��Ϣ
 * 		getName();
 * 		getPath();
 * 		getParent(); 
 * 
 * 
 * 
 */
public class IO_2 {
	public static void main1(String[] args) throws IOException {
		File f = new File("E:\\programming\\JAVA\\�����ļ�\\1.txt");
		//����
		System.out.println(f.createNewFile());
		//ɾ��
//		System.out.println(f.delete());
		
		//�ڳ����˳�ʱ���Զ�ɾ���ļ�������������쳣ɾ����
		f.deleteOnExit();
		
		for(int i=0;i<300000;i++){//Ϊ�˿�Ч��
			System.out.println(".");
		}
	}
	public static void main(String[] args) {
		//�����ļ���
		File dir = new File("E:\\programming\\JAVA\\�����ļ�\\1\\1\\2\\3\\4\\5");
		System.out.println(dir.mkdir());//��ഴ������Ŀ¼
		System.out.println(dir.mkdirs());//���Դ����༶Ŀ¼
		
		
		File f = new File("E:\\programming\\JAVA\\�����ļ�\\1.txt");
		System.out.println(f.exists());
	}
}
