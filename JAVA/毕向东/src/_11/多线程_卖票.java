package _11;
/*
 * ��Ʊ����
 * �����Ʊ��   һ����100��Ʊ
 */
class Ticket extends Thread{
	private static int num = 100;
	public void run(){
			while(num>0){
				System.out.println(Thread.currentThread().getName()+" ������"+num+" ��Ʊ");
				num--;//����һ������,������߳�ͬʱ���е��⻹û��num--;����ͬʱ��ӡ4��100
			}
	}
}
public class ���߳�_��Ʊ {
	public static void main(String[] args) {
		new Ticket().start();
		new Ticket().start();
		new Ticket().start();
		new Ticket().start();		
	}
}
