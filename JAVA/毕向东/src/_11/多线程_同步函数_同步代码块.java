package _11;
/*
 * ͬ��������õ�������һ����
 * ͬ�������õĵ�������this������Ҫ��������ã���ô��������һ�������������ã�����this��
 * 
 * ��������������֤ͬ�����������ǲ���this
 * 
 * ���������
 * ����֪�����߳��а�ת��������������   ͬ��������ͬ���������Խ��
 * 
 * ���ǽ������������ǰ�᣺ 1���߳����������������ϣ�����ͬ�����е�����
 * 						  2���õ���ͬһ����
 * 
 * ������ͬʱ��-----ͬ������_and ͬ�������-----����ͬһ�����⡣��
 * ���-----ͬ������_and ͬ������---������һ������ô���а�ȫ������
 * �����һ������ô������   ������������ǰ�ᡣ����û�а�ȫ����
 */
class Tecket4 implements Runnable{
	private int num = 100;
	boolean flag = true;
	Object obj = new Object();
	public void run(){
		
		if(flag){
			// ��ͬ������飺
			while(num>0){
				synchronized(this){//�������  obj  ��ô�õ��ǲ�ͬ�������������Ϊ0			�����   this  ��ôʼ�ղ����ܳ���0
					
					try {Thread.sleep(10);} catch (Exception e) {}
					
					if(num>0)
					System.out.println(Thread.currentThread().getName()+"  flag = "+flag+"  num = "+num--);
				}
			}
		}
		else
			while(num>0)
				show();//ͬ������
	}
	
	public synchronized void show(){
			try {Thread.sleep(10);} catch (Exception e) {}
			
			if(num>0)
			System.out.println(Thread.currentThread().getName()+"  num = "+num--);
	}
}
public class ���߳�_ͬ������_ͬ������� {
	public static void main(String[] args) {
		Tecket4 t = new Tecket4();
		new Thread(t).start();
		
		try {Thread.sleep(10);} catch (Exception e) {}//��ͣ���������߳�ִ��ͬ������飬Ϊ����һ�£�ͬ����������
		t.flag = false;
		
		new Thread(t).start();
		/*
		 * ���������߳�֮�⣬�������߳�ʱ���������̣߳��ֱ���뵽ͬ��������ͬ������
		 * ��ȥ֮�������߳̾Ͳ���ͻ�ˣ�������ǿռ��Դ������
		 */
	}
}
