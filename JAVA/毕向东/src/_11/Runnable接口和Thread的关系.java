package _11;
/*
 * ��������ģ��һ�����������ʹ��  Runnable  ���ı�   Thread ����Ĵ����
 * 
 * ̫����Լ��ˣ�����ȫ���Լ����  ����������ֻ�Ǵ��µķ��򡣡�����Ĵ��벻������
 */
interface Runnable1{
	public void run();
}

class Thread1 implements Runnable1{
	public Runnable1 r ;
	Thread1(){}
	Thread1(Runnable1 r){
		this.r = r;
	}
	
	public void run(){
		System.out.println("\n����������Ӧ���ǲ��Ŷ����ġ���Ϊ����ʾ");
	}
	
	public void start(){
		if(r!=null)
		this.r.run();
		else
			run();
	}
}

//��������Ҫ���ı�Thread�����run����
class dong implements Runnable1{
	public void run(){
		for(int x = 0;x<10;x++)
			System.out.print(x+" ");
	}
}

public class Runnable�ӿں�Thread�Ĺ�ϵ {
	public static void main(String[] args) {
		dong d = new dong();
		new Thread1(d).start();//�����Ͱ�    ���ǵĴ���    dong  ����  run   �Ĵ���   
		
		new Thread1().start();//����  d   ��ִ�� Thread1�Լ���run      ����d  ��ִ��d �����run
	}
}
