package _11;
/*
 * ��������⣺
 * 1����ȷ��Щ�����Ƕ��߳����д���
 * 2����ȷ��������
 * 3����ȷ���߳����д�������Щ����ǲ����˹�������
 * 
 */
class Bank{
	private int sum;
	public synchronized void add(int n,int i){//���߳�ͬ����������������ֱ���ں����ϼ���    synchronized   
		sum+=n;
		try {
			Thread.sleep(10);
		} catch (Exception e) {
			// TODO: handle exception
		}
		System.out.println(Thread.currentThread().getName()+".."+sum+"\ti = "+i);
	}
}
class Cun implements Runnable{
	private Bank b = new Bank();
	private int x;
	public void run(){
//		for(x=0;x<3;x++){			//����    for()ѭ����һ������   �����   x   �������̵߳Ĺ�������	������Ҳ����һ����ȫ������
//			b.add(100,x);
//		}
		for(int y=10;y<13;y++){		//  �����߳��õ����ǲ�ͬ��y    y�����ڹ������ݣ����൱�� һ����   y1   һ����     y2
			b.add(100, y);
		}
	}
}
public class ���߳�_ͬ������ {
	public static void main(String[] args) {
		Cun c = new Cun();
		
		new Thread(c).start();
		new Thread(c).start();		
	}
}
