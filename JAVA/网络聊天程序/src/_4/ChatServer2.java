package _4;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class ChatServer2 {
	public static void main(String[] args) {
		Socket s = null;
		int count = 1;
		try {
//			ServerSocket ss = new ServerSocket(8888);//����������10001
			ServerSocket ss = new ServerSocket(8888);//����������
			
			
			while(true){
				s = ss.accept();//���տͻ�������
				new ServerFrame(s,count++).launchFrame();//ÿ����һ���ͻ��˾ʹ���һ���߳�
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
//ʹ������п��Ӵ���
class ServerFrame extends Frame{
	Socket s = null;
	PrintWriter pw ;
	BufferedReader bufr;
	String str = null;
	int count = 0 ;
	TextField tf = new TextField();
	TextArea ta = new TextArea();
	
	ServerFrame(Socket s,int count){
		this.s = s;
		this.count = count;
	}
	//��Ҫ���ǵ����������
	public void launchFrame(){
		setTitle("��ӭ��������������");
		setBounds(400,100,700,600);
		
		add(ta);
		add(tf,BorderLayout.SOUTH);
		pack();
		this.addWindowListener(new WindowAdapter(){//�رմ���ʱ
			public void windowClosing(WindowEvent e) {
				disconnect();
			}
		});
		tf.addActionListener(new TFListener());//����TestField����
		setVisible(true);
		
		new Thread(new ClientReader()).start();//Ϊ��ȡ�ͻ���ר�Ŵ���һ���߳�
	}
	//����TextField�ļ���
	private class TFListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			String str = tf.getText().trim();//��ȡTestField���������
			ta.append("��������"+str+"\r\n");//��TextArea�д�ӡ		TestField���������
			tf.setText("");//���TestField
			try {
				pw = new PrintWriter(s.getOutputStream(),true);
				pw.println(str);
			} catch (Exception e1) {
				e1.printStackTrace();
			}
		}
	}
	private void disconnect(){
		try {
			setVisible(false);
			if(s!=null)
			s.close();
		} catch (IOException e) {
			return ;
		}
		pw.close();
	}
	
	class ClientReader implements Runnable{
		private String str = null;
		public void run() {
			ta.append("Client��"+count+"  ����\r\n");
			while(s!=null){
				try {
					bufr = new BufferedReader(new InputStreamReader(s.getInputStream()));
					if((str = bufr.readLine())== null){
						bufr.close();
						return ;
					}
					ta.append("Client��"+str+"\r\n");
					} catch (IOException e) {
//						System.out.println("�ͻ����˳�");
						return ;
					}
			}
		}
	}
}
