package _12;
/*
 * ���ֹͣ�߳�
 * ֻ��һ�֣���run()��������
 * �������߳����У����д���ͨ����ѭ���ṹ
 * 
 * ֻҪ����ѭ�����Ϳ�����run����������Ҳ�����߳̽���
 */
class StopThread implements Runnable{
	private boolean f = true;
	public synchronized void run(){
		while(f){
			try {
				wait();
			} catch (InterruptedException e) {//��   �̴߳�  wait ״̬  ��  interrupt ���ѣ����wati״̬�����ͻᷢ���쳣������notify��Щ����������
				System.out.println(Thread.currentThread().getName()+"          Exception");
				f = false;//ÿ��interrupt���ỽ�ѣ�����ѭ��һ���ֱ�  wait  ����  ����������洦���߳̽����Ĳ��������߳��˳�ѭ��
			}
			System.out.println(Thread.currentThread().getName()+"               runing");	//��û���쳣����ʱ  ִ����
		}
	}
}
public class ֹͣ�߳� {
	public static void main(String[] args) {
		StopThread s = new StopThread();
		Thread t1 = new Thread(s);
		Thread t2 = new Thread(s);
		t1.start();
		t2.start();
		
		for(int i=0;i<60;i++)
			System.out.println(Thread.currentThread().getName()+"    runing");
		
		t1.interrupt();// ���߳�  ��  wati  and  sleep ��Щ˯��״̬     �ָ������������̣߳�
		t2.interrupt();
		System.out.println("over");
	}
}
