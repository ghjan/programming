package _19;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

/*
 * 
 */
public class IO_3_����һ��ͼƬ {
	public static void main(String[] args) {
		FileOutputStream fos = null;
		FileInputStream fis = null;
		
		try {
			fis = new FileInputStream("C:\\Users\\37916\\Pictures\\Camera Roll\\��.jpg");//��
			fos = new FileOutputStream("C:\\Users\\37916\\Desktop\\1.png");					//д	
			
			byte[] buf = new byte[1024];
			int len = 0;
			while((len = fis.read(buf))!= -1){//�Ӵ��������н���� buf.length ���ֽڵ����ݶ���һ�� byte ������   ���ûӴ�������Ƕ�һ���ֽ�
				fos.write(buf,0,len);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally{
			if(fos == null)
				try {
					fos.close();
				} catch (Exception e2) {
					// TODO: handle exception
				}
			if(fis == null)
				try {
					fis.close();
				} catch (Exception e2) {
					// TODO: handle exception
				}
		}
		
		
	}
}
