package _23;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class _7_�Զ������� {
	public static void main(String[] args) throws IOException {
		ServerSocket ss = new ServerSocket(10003);
		while(true){
			Socket s = ss.accept();
			System.out.println(s.getInetAddress().getHostAddress());
			
			PrintWriter pw = new PrintWriter(s.getOutputStream(),true);
			
			pw.println("<font color='red' size='7'>��ӭ�����ҵķ�����</font>\r\n");
			pw.println("<font color='red' size='7'>��ӭ�����ҵķ�����</font>");
			pw.println("<font color='red' size='7'>��ӭ�����ҵķ�����</font>");
			s.close();
		}
	}
}
