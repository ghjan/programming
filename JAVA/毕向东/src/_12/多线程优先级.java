package _12;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

class Priority implements Runnable{
	
	public void run(){
		for(int i=0;i<10;i++){
			System.out.println(Thread.currentThread().toString());//toString() ���ظ��̵߳��ַ�����ʾ��ʽ�������߳����ơ����ȼ���   �߳��顣
			//Thread.yield();//��ͣ��ǰ����ִ�е��̶߳��󣬲�ִ�������̡߳�
		}
		
		
	}
}
public class ���߳����ȼ� {
	public static void main(String[] args) throws InterruptedException {
		System.out.println("�����ȼ���"+Thread.MAX_PRIORITY);
		System.out.println("Ĭ�ϣ�"+Thread.NORM_PRIORITY);
		System.out.println("Ĭ�ϣ�"+Thread.MIN_PRIORITY);
		
		Priority p = new Priority();
		
		
		Thread t1 = new Thread(p);
//		t1.join();
		Thread t2 = new Thread(p);

		t1.setPriority(Thread.MAX_PRIORITY);
		t1.start();
		t2.start();
		
	}
}
