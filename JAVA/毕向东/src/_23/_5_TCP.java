package _23;

import java.net.*;
import java.io.*;

public class _5_TCP {
	public static void main(String[] args) throws Exception {
		//�����ͷ��˵�socket����ָ��Ŀ�������Ͷ˿�
		Socket s = new Socket("192.168.1.1",10000);
		
		//Ϊ�˷������ݣ�Ӧ�û�ȡsocket���е������
		OutputStream out = s.getOutputStream();
		out.write("���ǿͻ���".getBytes());
		
		//�����������
		InputStream in = s.getInputStream();
		byte[] buf = new byte[1024];
		int len = in.read(buf);
		System.out.println(new String(buf,0,len));
		
		s.close();
	}
}
