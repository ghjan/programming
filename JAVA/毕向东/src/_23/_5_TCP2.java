package _23;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class _5_TCP2 {
	public static void main(String[] args) throws IOException, InterruptedException {
		//����������socket���񣬲�����һ���˿�
		ServerSocket ss = new ServerSocket(10000);
		
		while(true){
		Socket s = ss.accept();
		
		//��ȡ�ͷ��˷����������ݣ���ôҪʹ�ÿͻ��˶���Ķ�ȡ������ȡ����
		InputStream in = s.getInputStream();
		
		byte[] buf = new byte[1024];
		int len = in.read(buf);
		System.out.println(s.getInetAddress().getHostAddress());//public InetAddress getInetAddress()�����׽������ӵĵ�ַ��
																//����ֵ��һ������ͨ�����������ض�����ͨ�������ȡ��ַ
																//String getHostName() ��ȡ�� IP ��ַ�������� 
		System.out.println(new String(buf,0,len));
		
		//���ͻ��˷�������
		OutputStream out = s.getOutputStream();
		Thread.sleep(4000);//�������ͣ4���ٸ��ͻ��˷�������
		out.write("������յ���".getBytes());
		
		s.close();//�رտͻ���
		}
	}
}
