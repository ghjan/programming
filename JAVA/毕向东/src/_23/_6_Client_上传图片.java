package _23;

import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
/*
 * ���ǳ�����ȫ�Լ�д��û�г���Ƶ
 * ʵ���ϴ�ͼƬ����
 * ����Ҳ�кö�ûŪ����
 * ��Щû�����׵Ķ����������ˣ�����һ���ر𱿵ķ�����������
 * 
 * 1����ȡ�ļ������ȣ������������ת��Ϊ���ַ���(ռһ���ֽ�)��Ȼ����תΪ�ֽ����鷢��ȥ(����ȥһ���ֽ�)
 */
public class _6_Client_�ϴ�ͼƬ {
	public static void main(String[] args) throws Exception {
		Socket s = new Socket("192.168.1.1",10006);
		
		String name = "4.jpg";
		FileInputStream fis = new FileInputStream("C:\\Users\\37916\\Pictures\\Camera Roll\\"+name);
		OutputStream os = s.getOutputStream();
		
		byte[] buf = new byte[1024];
		int len = 0;
		
//		String l = name.length() + "";//�ַ���		һ���ַ�1�ֽ�  ���������ֽ�
//		os.write(l.getBytes());//����һ���ֽ�
		//����
		buf[0] = (byte)name.length();//������ǿ������ת���Ϳ�����
		os.write(buf,0,1);
		
		buf = name.getBytes();
		os.write(buf);
		
		while((len = fis.read(buf))!=-1){
			os.write(buf,0,len);
		}
		
		s.shutdownOutput();//�رտͻ�����������൱�ڸ����м���һ���������-1, ��������˾Ϳ�������whileѭ��
		
		InputStream is = s.getInputStream();
		byte[] buf1 = new byte[1024];
		int l = is.read(buf1);
		System.out.println(new String(buf1,0,l));
		
		is.close();
		os.close();
		fis.close();
	}
}
