package _4;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
/*
 *  void setTitle(String title)    ���˴���ı�������Ϊָ�����ַ����� 
 */
public class ChatClient extends Frame{
	Socket s ;
	PrintWriter pw ;
	TextField tf = new TextField();
	TextArea ta = new TextArea();
	Dialog Dia = new Dialog(this,"�ǵó����氡",true);
	Button okButton = new Button("��Ҫ��/(��o��)/~~����                   ���ҵ���");
	
	public void launchFrame(){
		setTitle("��ӭ��������������");
		setBounds(400,100,600,500);
		
		add(ta);					//��TextArea����
		add(tf,BorderLayout.SOUTH);//��TextField�ŵ��ϱ�
		Dia.add(okButton);//�ɼӿɲ��ӣ�Ϊ������
		Dia.setBounds(500,300,300,100);//�Ի����е�λ��+��С
		
		pack();//�Զ��������ʵĴ�С
		//���ڹر�ʱ�Ķ���
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				disconnect();
				System.exit(0);
			}
		});
		//�Ի���ر�ʱ�Ķ���
		Dia.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				Dia.setVisible(false);
			}
		});
		
		tf.addActionListener(new TFListener());//��TextField�У�����TestField����
		setVisible(true);
		
		connect();//���ӷ�����
		
		ta.append("�����ͷ�����ӭ�����������ˣ���������������ѯ���⣨�Իس�������\r\n�����ͷ���������ʲô���԰����ô?\r\n");
		
		new Thread(new ServerReadr()).start();//������
	}
	
	//����TextField�ļ���
	private class TFListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			String str = tf.getText().trim();//��ȡTestField���������
			ta.append("me�ң�"+str+"\r\n");//��TextArea�д�ӡ		TestField���������
			tf.setText("");//���TestField
			try {
				pw.println(str);
			} catch (Exception e1) {
				e1.printStackTrace();
			}
		}
	}
	//��������ʱ�Ĳ���
	public void connect(){
		try {
			s = new Socket("192.168.1.1",8888);
//			s= new Socket("chenmingdong666.6655.la",29597);
			pw = new PrintWriter(s.getOutputStream(),true);
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	//�ر�ʱ�Ĳ���
	public void disconnect(){
		try {
			Dia.setVisible(true);
			pw.println("���˳���");
			s.shutdownOutput();
			s.close();
		} catch (IOException e) {
			return ;
		}
		pw.close();
	}
	//��ȡ����������������Ϣ
	class ServerReadr implements Runnable{
		private BufferedReader bufr;
		private String str = null;
		public void run() {
			while(s!=null){
				try {
					bufr = new BufferedReader(new InputStreamReader(s.getInputStream()));
					if((str = bufr.readLine())== null){
						bufr.close();
						return ;
					}
					ta.append("�����ͷ���"+str+"\r\n");
					} catch (IOException e) {
						return ;
					}
			}
		}
	}
	
	public static void main(String[] args) {
		new ChatClient().launchFrame();
	}
}
