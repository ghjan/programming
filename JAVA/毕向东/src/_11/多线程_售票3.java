package _11;
/*
 * ��һ���������һ�����⣺�������ظ��������и���
 * ԭ��
 * ����������ڲ���ͬһ���̹߳�������ʱ�������Ĵ���
 * 
 * ���������
 * 
 * ͬ�������
 * synchronized(����)
 * {	ͬ�������	}
 * 
 * �����������߳�(thread1��thread2)����ͬһ������(syncThread)�е�synchronized�����ʱ��
 * ��ͬһʱ��ֻ����һ���̵߳õ�ִ�У���һ���߳�������������ȴ���ǰ�߳�ִ�������������Ժ����ִ�иô���顣
 * Thread1��thread2�ǻ���ģ���Ϊ��ִ��synchronized�����ʱ��������ǰ�Ķ���
 * ֻ��ִ����ô��������ͷŸö���������һ���̲߳���ִ�в������ö���
 * 
 * �ô���
 * ����˶��̰߳�ȫ����
 * �׶ˣ�
 * ���߳�Ҫ�ж�����������Դ
 */

class Ticket3 implements Runnable{
	private int num = 100;				//����û��static
	Object obj = new Object();
	public void run(){
		
		while(num>0){
			
			synchronized (obj) {//��֤��ÿ�ν������߳�ֻ��һ���������ȿ��Ա�֤��ӡ��˳���ֱ�֤��û���ظ������������ĸ��̶߳�����ִ�е����������������һ���и���
//				try {
//				Thread.sleep(10);
//			} catch (Exception e) {
//				// TODO: handle exception
//			}
				if(num>0)//��һ����֤��    û�и��� 
				System.out.println(Thread.currentThread().getName()+" ������"+num--+" ��Ʊ");
			}
			
		}
	}
}
public class ���߳�_��Ʊ3 {
	public static void main(String[] args) {
		Ticket3 t = new Ticket3();
		
		new Thread(t).start();//���ڶ���ʹ��  t ������������ĸ��߳�ͨ��һ����     ��ȻҲ���ü�static��  
		new Thread(t).start();
		new Thread(t).start();
		new Thread(t).start();
	}
}
