package _23;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

/*
 * ˼·
 * 1������udpsocket����,ͨ�������һ��ָ���˿�
 * 2������һ�����ݰ�������������յ������ݣ���Ϊ���ݰ��������и��๦�ܿ�����ȡ�ֽ������еĲ�ͬ������Ϣ
 * 3��ͨ��socket�����receive�������յ������ݴ����Ѷ���õ����ݰ���
 * 4��ͨ�����ݰ���������й��ܣ�����Щ��ͬ������ȡ��
 * 5���ر���Դ
 */
public class _3_UDP {
	public static void main(String[] args) throws Exception {
		//1������UDP socket�������˵�
		DatagramSocket ds = new DatagramSocket(10001);//���ͷ���ָ���˿�
		while(true){
			//2���������ݰ������ڴ�������
			byte[] buf = new byte[1024];
			DatagramPacket dp = new DatagramPacket(buf,buf.length);
			//3��ͨ�������receive�������ܵ������ݴ������ݰ���
			ds.receive(dp);
			//4,ͨ�����ݰ��ķ�����ȡ���е�����
			String ip = dp.getAddress().getHostAddress();
			
			String data = new String(dp.getData(),0,dp.getLength());
			
			int port = dp.getPort();
			
			System.out.println("ip��"+ip);
			System.out.println("data��"+data);
			System.out.println("port��"+port);
		}
	}
}
