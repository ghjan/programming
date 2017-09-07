package _12;
/*
 * JDK1.5���ṩ��   Lock
 * synchronized ת����ʵ�� Lock ����
 * 
 * �·���Lock
 * 
 * Lock lock = new ReentrantLock();
 * Condition condition_pro = lock.newCondition();
 * Condition condition_con = lock.newCondition();
 * 
 * lock.lock();
 * 
 * condition_pro.await();//���̵߳ȴ�
 * condition_con.signal();//���ѶԷ��߳�
 * 
 * lock.unlock();
 */
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Resource2{
	private String name;
	private boolean flag = false;
	
	private Lock lock = new ReentrantLock();
	private Condition condition_pro = lock.newCondition();
	private Condition condition_con = lock.newCondition();
	
	public void set(String name){
		lock.lock();
		try {
			while(flag)
				condition_pro.await();//���̵߳ȴ�
			this.name = name;
			System.out.println(Thread.currentThread().getName()+"...����.."+this.name);
			flag = true;
			condition_con.signal();//���ѶԷ��߳�
		} catch(InterruptedException e){
			System.out.println("����");
		}finally {
			lock.unlock();
		}


	}
	public void out(){
		lock.lock();
		try {
			while(!flag)
				condition_con.await();
		System.out.println(Thread.currentThread().getName()+"...����******"+this.name);
		flag = false;
		condition_pro.signal();
		} catch(InterruptedException e){
			System.out.println("����");
		}finally {
			lock.unlock();
		}
	}
}
class Producer2 implements Runnable{
	private int num = 1;
	private Resource2 r;
	Producer2(Resource2 r){
		this.r = r;
	}
	public void run(){
		while(num<60)
			r.set("��Ʒ("+(num++)+")");
	}
}
class Consumer2 implements Runnable{
	private int num = 1;
	private Resource2 r;
	Consumer2(Resource2 r){
		this.r = r;
	}
	public void run(){
		while(num++<60)
			r.out();
	}
}
public class �߳�ͨ��_��ϰ_lock���ͬ�� {
	public static void main(String[] args) {
		Resource2 r = new Resource2();
		
		Producer2 p = new Producer2(r);
		Consumer2 c = new Consumer2(r);
		
		new Thread(p).start();;
		new Thread(p).start();;
		new Thread(c).start();;
		new Thread(c).start();;
		
		
	}
}
