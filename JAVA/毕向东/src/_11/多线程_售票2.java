package _11;
/*
 * �����̵߳ĵڶ��ַ�ʽ��ʵ��Runable�ӿ�
 * 
 * ����
 * 1��������ʵ��Runnable�ӿ�
 * 2������Runnable�ӿ��е�run����
 * 3��ͨ��Thread�ཨ���̶߳���
 * 4����Runnable�ӿڵ����������Ϊʵ�ʲ�������Thread��Ĺ��캯��
 * 5������Thread���start���������̲߳�����Runnable�ӿ������run����
 * 
 * ʵ�ַ�ʽ�ͼ̳з�ʽ��ʲô����
 * ʵ�ַ�ʽ�ô��������˵��̳еľ�����
 * �ڶ����߳�ʱ������ʹ��ʵ�ַ�ʽ
 * �������������������������������������ӿڿ���ʵ�ֶ�̳�
 * 
 * ���ַ�ʽ���𣺣����λ�ò�һ����
 * �̳�Thread��     �̴߳�����Thread����run������
 * ʵ��Runnable���̴߳�����ڽӿڵ������run����
 */
class Ticket2 implements Runnable{
	private int num = 100;				//����û��static   
	public void run(){
			while(num>0){
//				try {
//					Thread.sleep(10);		//����֮����ܿ����и���
//				} catch (Exception e) {
//					// TODO: handle exception
//				}
				System.out.println(Thread.currentThread().getName()+" ������"+num+" ��Ʊ");
				num--;
			}
	}
}
public class ���߳�_��Ʊ2 {
	public static void main(String[] args) {
		Ticket2 t = new Ticket2();
		
		new Thread(t).start();//���ڶ���ʹ��  t ������������ĸ��߳�ͨ��һ����     ��ȻҲ���ü�static��  
		new Thread(t).start();
		new Thread(t).start();
		new Thread(t).start();
	}
}
