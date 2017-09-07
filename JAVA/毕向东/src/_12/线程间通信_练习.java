package _12;
/*
 *�������������������������ߣ������̼߳�ͨ��
 * 
 * ������Ѿ����ڲ��������̡߳����������߳���4���߳�
 * 
 */
class Resource{
	private String name;
	private boolean flag = false;
	
	public synchronized void set(String name){
		while(flag)//ע�����ﲻ��  if Ŀ�ģ��ñ����ѵ��߳���һ���жϱ��
			try {
				wait();
			} catch (Exception e) {
			}
		this.name = name;
		System.out.println(Thread.currentThread().getName()+"...����..."+this.name);
		flag = true;
		notifyAll();//ע����ȫ�����ѡ����������ȫ�����ѣ����п��ܾ��ǻ���  �������̡߳����¶Է��߳�ʼ�����������յ��£�ȫ���߳�˯��
	}
	public synchronized void out(){
		while(!flag)//ע�����ﲻ��  if Ŀ�ģ��ñ����ѵ��߳���һ���жϱ��
			try {
				wait();
			} catch (Exception e) {
			}
		System.out.println(Thread.currentThread().getName()+"...����*****"+this.name);
		flag = false;
		notifyAll();
	}
}
class Producer implements Runnable{
	private int num = 1;
	private Resource r;
	Producer(Resource r){
		this.r = r;
	}
	public void run(){
		while(true)
			r.set("��Ʒ("+(num++)+")");
	}
}
class Consumer implements Runnable{
	private Resource r;
	Consumer(Resource r){
		this.r = r;
	}
	public void run(){
		while(true)
			r.out();
	}
}
public class �̼߳�ͨ��_��ϰ {
	public static void main(String[] args) {
		Resource r = new Resource();
		
		Producer p = new Producer(r);
		Consumer c = new Consumer(r);
		
		new Thread(p).start();;
		new Thread(p).start();;
		new Thread(c).start();;
		new Thread(c).start();;
		
		
	}
}
