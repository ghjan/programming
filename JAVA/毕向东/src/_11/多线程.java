package _11;
/*
 * ÿ�����еĽ������һ��
 * ��Ϊ����̶߳���ȡcpuִ��Ȩ��CPUִ�е�˭��������˭
 * ��ȷ����ĳ��ʱ��ֻ����һ�����������С�����˳��⣩
 * 
 * 
 * 
 * ������ִ���߳������ַ�����һ�ַ����ǽ�������Ϊ Thread �����ࡣ������Ӧ��д Thread ��� run ������
 * ���������Է��䲢�����������ʵ�������磬�������ĳһ�涨ֵ���������߳̿���д�ɣ� 
--------------------------------------------------------------------------------

     class PrimeThread extends Thread {
         long minPrime;
         PrimeThread(long minPrime) {
             this.minPrime = minPrime;
         }
 
         public void run() {
             // compute primes larger than minPrime
              . . .
         }
     }
 
--------------------------------------------------------------------------------

Ȼ�����д���ᴴ��������һ���̣߳� 


     PrimeThread p = new PrimeThread(143);
     p.start();
 �����̵߳���һ�ַ���������ʵ�� Runnable �ӿڵ��ࡣ����Ȼ��ʵ�� run ������Ȼ����Է�������ʵ��,
 �ڴ��� Thread ʱ��Ϊһ�����������ݲ��������������ַ���ͬһ������������ʾ�� 



--------------------------------------------------------------------------------

     class PrimeRun implements Runnable {
         long minPrime;
         PrimeRun(long minPrime) {
             this.minPrime = minPrime;
         }
 
         public void run() {
             // compute primes larger than minPrime
              . . .
         }
     }
 
--------------------------------------------------------------------------------

Ȼ�����д���ᴴ��������һ���̣߳� 


     PrimeRun p = new PrimeRun(143);
     new Thread(p).start();
 ÿ���̶߳���һ����ʶ��������߳̿���ͬ��������̴߳���ʱû��ָ����ʶ�����ͻ�Ϊ������һ�������ơ� 


 * 
 */
class PrimeThread extends Thread{
	public void run(){
		for(int i=0;i<60;i++){
			System.out.println("PrimeThread �߳�����");
		}
	}
}

public class ���߳� {
	public static void main(String[] args) {
		PrimeThread p = new PrimeThread();
		p.start(); //		 void start() ʹ���߳̿�ʼִ�У�Java ��������ø��̵߳� run ������ 
		
		for(int i=0 ;i<60;i++){
			System.out.println("main �߳�����");
		}
	}
}
