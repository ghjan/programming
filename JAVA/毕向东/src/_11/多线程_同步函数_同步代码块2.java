package _11;
/*
 * ͬ����������̬���κ�
 * 
 * ͨ����֤�����ֲ���this   ��Ϊ��̬�����в����Զ���this
 * 
 * ��̬���ڴ���û�б�����󣬵���һ���и����Ӧ���ֽ����ļ�����
 * ����.class  �ö����������Class
 * 
 * ��̬��ͬ��������ʹ�õ����Ǹ÷�����������ֽ����ļ�����
 */
class Tecket5 implements Runnable{
	private static int num = 100;
	boolean flag = true;
	Object obj = new Object();
	public void run(){
		
		if(flag){
			// ��ͬ������飺
			while(num>0){
				synchronized(Tecket5.class){
					
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
	
	public static synchronized void show(){
			try {Thread.sleep(10);} catch (Exception e) {}
			
			if(num>0)
			System.out.println(Thread.currentThread().getName()+"  num = "+num--);
	}
}
public class ���߳�_ͬ������_ͬ�������2 {
	public static void main(String[] args) {
		Tecket5 t = new Tecket5();
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
