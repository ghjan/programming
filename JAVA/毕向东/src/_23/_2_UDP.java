package _23;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.UnknownHostException;

/*
 * ����ͨ��udp���䷽ʽ����һ���������ݷ��ͳ�ȥ
 * 
 * 1������updsocket
 * 2���ṩ���ݣ��������ݷ�װ�����ݰ���
 * 3��ͨ��socket����ķ��͹��ܣ������ݰ����ͳ�ȥ
 * 4���ر���Դ
 */
public class _2_UDP {
	public static void main(String[] args) throws Exception {
		//1������udp����
		DatagramSocket ds = new DatagramSocket(8888);//�������ָ���˿�
		
		//2��ȷ�����ݣ�����װ�����ݰ�
		byte[] buf = "hello udp dong".getBytes();
		DatagramPacket dp = new DatagramPacket(buf,buf.length,InetAddress.getByName("192.168.1.1"),10000);
		
		ds.send(dp);//����
		ds.close();
	}
}
