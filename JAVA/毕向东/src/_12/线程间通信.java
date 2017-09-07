package _12;
/*
 * Input��  Res ����д���ݣ�Output��Res���������
 * 
 * ע�⣺1�������̶߳�����ͬʱͬ��������ֻͬ��һ��
 *       2�������̱߳�����ͬһ������ͬһ�������
 *       
 *  wait;
 *  notify();
 *  notifyAll();
 *  ��ʹ����ͬ���У���ΪҪ���м��������������̲߳���
 *  ����Ҫʹ����ͬ���У���Ϊֻ��ͬ��������
 *  
 *  Ϊʲô��Щ�����̵߳ķ���Ҫ������Object�У�
 *  ��Ϊ����Щ�����ڲ���ͬ�����߳�ʱ��������Ҫ��ʶ�����������̵߳���
 *  ֻ��ͬһ�����ϵı��ȴ��̣߳����Ա�ͬһ�����ϵ�notefy����
 *  �����ԶԲ�ͬ���е��̻߳���
 *  
 *  Ҳ����˵���ȴ��ͻ��ѱ�����ͬһ����
 *  
 *  ��������������������Կ��Ա����������õķ���������Object����
 */
class Res{
	public String name ;
	public String sex;
	public boolean f  = false;//false��ʾ��û�б���ȡ������Ϊ��
}
class Input implements Runnable{
	private Res r;
	Input(Res r){
		this.r = r;
	}
	public void run(){
		int x = 0;
		while(true){
			synchronized(Input.class){
				if(r.f)
					try{Input.class.wait();} catch(Exception e){}
				if(x == 0){
					r.name = "dong";
					r.sex = "man";
				}
				else{
					r.name = "����";
					r.sex = "Ů";
				}
				r.f = true;
				Input.class.notify();
				x = (x+1)%2;
			}
		}
	}
}
class Output implements Runnable{
	private Res r;
	Output(Res r){
		this.r = r;
	}
	public void run(){
		while(true){
			synchronized(Input.class){
				if(!r.f)
					try{Input.class.wait();} catch(Exception e){}
				System.out.println(r.name+"    "+r.sex);
				r.f = false;
				Input.class.notify();
			}
		}
	}
}
public class �̼߳�ͨ�� {
	public static void main(String[] args) {
		Res r = new Res();
		Input i = new Input(r);
		Output o = new Output(r);
		
		new Thread(i).start();
		new Thread(o).start();
		
	}
}
