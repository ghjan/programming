package _23;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

class Server implements Runnable{
	private Socket s;
	Server(Socket s){
		this.s = s;
	}
	public void run(){
		try {
			
			System.out.println("IP:"+s.getInetAddress().getHostAddress());//��ӡ�ͻ���IP
			
			InputStream is = s.getInputStream();//������ȡ��
			
			byte[] buf = new byte[1024];
			int len = 0;
			
			is.read(buf,0,1);//�ѷ������������ֽڵ�һ���ֽڴ�����
//			len = buf[0] - '0';//����������һ���ַ���Ҳ������
			len = (int )buf[0];//
			is.read(buf,0,len);
			String name = new String(buf,0,len);
			FileOutputStream fis = new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\"+name);//�ѽ�Ҫ���͹�����ͼƬ����һ�������λ��
			
			while((len = is.read(buf))!=-1){//�����is����InputStream		��Ӧ�ͷ��˵�OutputStream
				fis.write(buf,0,len);
			}
			
			OutputStream os = s.getOutputStream();
			os.write("�ϴ��ɹ�".getBytes());
			
			os.close();
			fis.close();
			is.close();
		} catch (Exception e) {
			throw new RuntimeException("�ϴ�ʧ��");
		}
	}
	
}
public class _6_Server_�ϴ�ͼƬ {
	public static void main(String[] args) throws Exception {
		ServerSocket ss = new ServerSocket(10006);//���Ҫ��IOException		//�����˿�Ϊ10000�����
		
		while(true){
			Socket s = ss.accept();//���տͻ���
			new Thread(new Server(s)).start();
		}
	}
}
