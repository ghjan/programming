package _20;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class IO_12_�и��Ӱ {
	public static void main(String[] args) throws IOException {
		splitFile();
	}
	public static void splitFile() throws IOException{
		FileInputStream fis = new FileInputStream("E:\\study_materials\\JAVA\\����\\05\\�������Ա_����_Java������Ƶ�̵̳�05��-03-�������(�������Ĺ�ϵ).avi");
		FileOutputStream fos = null;
		
		byte[] buf = new byte[1024*1024];
		int len;
		for(int i=0;i<3;i++){//����ж�Ҫ�����ļ���װ
			fos = new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\��"+i+".part");
			for(int j=0;j<20;j++){//ÿһ����Ƭ�ļ�ѭ��д��50�Σ�ÿ��д�����1M��������������   һ����Ƭ�ļ�50M
				len = fis.read(buf);
				if(len == -1) break;//û����仰  ��Ȼ���һ����������ʦ�ᱨ����ԭ����� len != -1  ���û����仰     write �ͻ�д��  0,-1������ֵ
				fos.write(buf,0,len);
			}
			fos.close();
		}
		fis.close();
	}
}
