package _11;
/*
 * ÿ�����еĽ������һ��
 * ��Ϊ����̶߳���ȡcpuִ��Ȩ��CPUִ�е�˭��������˭
 * ��ȷ����ĳ��ʱ��ֻ����һ�����������С�����˳��⣩
 * 
 * static Thread currentThread();��ȡ��ǰ�̵߳Ķ���
 * getNmae():��ȡ�߳�����
 */
class PrimeThread2 extends Thread{
//	String name;
	public PrimeThread2(String name){
//		this.name = name;
		super(name);
	}
	
	public void run(){
		for(int i=0;i<60;i++){
			System.out.println((Thread.currentThread()==this)+" "+this.getName()+" �߳�����  "+i);//Thread.currentThread()==this
		}
	}
}

public class ���߳�_2 {
	public static void main(String[] args) {
		new PrimeThread2("��").start();
		new PrimeThread2("��").start();
		new PrimeThread2("��").start();
		
		for(int i=0 ;i<60;i++){
			System.out.println("main �߳����� "+i);
		}
	}
}
