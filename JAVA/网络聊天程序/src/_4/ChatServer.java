package _4;

import java.awt.Frame;
import java.io.*;
import java.net.*;
/*
 * ��γ����е�����
 */
public class ChatServer extends Frame{
	public static void main(String[] args) {
		Socket s = null;
		int count = 1;
		try {
			ServerSocket ss = new ServerSocket(8888);//����������
			
			while(true){
				s = ss.accept();//���տͻ�������
				new Thread(new ClientThread(s,count++)).start();//Ϊ�ͻ��˴����߳�
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
class ClientThread implements Runnable{
	Socket s = null;
	int count = 0;
	String str = null;
	ClientThread(Socket s,int count){
		this.s = s;
		this.count = count;
	}
	public void run() {
		System.out.println(s.getLocalAddress().getHostAddress()+"------connected");
		
		new Thread(new ServerSpeak()).start();//һ�������Ͼ�Ϊ  ���������ͻ��˷���Ϣ����һ���߳�
		
		BufferedReader dis = null;
		try {
			dis = new BufferedReader(new InputStreamReader(s.getInputStream()));
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		//������һֱ������
		try {
			while((str = dis.readLine())!=null){
				System.out.println("Client"+count+"��"+str);
			}
			s.close();
		} catch (IOException e) {
		}
	}
	
	class ServerSpeak implements Runnable{
		PrintWriter pw;
		BufferedReader bufr;
		String str2 ;
		public void run(){
			try {
				while(true){
					pw = new PrintWriter(s.getOutputStream(),true);
					bufr = new BufferedReader(new InputStreamReader(System.in));
					if((str2 = bufr.readLine()) == null){
						break;
					}
					pw.println(str2);
				}
			} catch (IOException e) {
				System.out.println("һ���ͷ����˳�");
				return ;
			} finally{
				try {
					bufr.close();
					pw.close();
//					s.close();
				} catch (IOException e) {
				}
			}
		}
	}
}
