package _18;

import java.util.Random;

public class _Math {
	public static void main(String[] args) {
		double d1 = Math.ceil(19.2);//���ش���ָ�����ݵ���С����
		double d2 = Math.ceil(-19.2);
		System.out.println(d1+"   "+d2);
		
		double d3 = Math.floor(12.34);//����С��ָ�����ݵ��������
		double d4 = Math.floor(-12.34);
		System.out.println(d3+"   "+d4);
		
		long l1 = Math.round(12.35);//��������
		long l2 = Math.round(12.55);
		System.out.println(l1+"   "+l2);
		
		double d5 = Math.pow(2, 3);//2��3�η�
		System.out.println((int)d5);//ǿתΪ����
		
		for(int i =0 ;i<3;i++)
		rand();//��ȡ�����
		
		//��һ�ֻ�ȡ���������
		Random r = new Random();
		for(int i=0;i<3;i++){
			int d = r.nextInt(10)+1;//�� 0����������ָ��ֵ����������֮����ȷֲ��� int ֵ
			System.out.println(d);
		}
		
		String df = new java.text.DecimalFormat("#.00").format(213.43214);//������λС��    #.00��ʾ������λ 
		System.out.println(df);
		String df2 = new java.text.DecimalFormat("#.000").format(213.43214);//������λС��    #.00��ʾ����3λ
		System.out.println(Double.parseDouble(df2));
	}
	public static void rand(){
//		double d = Math.random();//��ȡ�������0-1֮�������������1����0��
		int d = (int)(Math.random()*10+1);
		System.out.println(d);
	}
}
