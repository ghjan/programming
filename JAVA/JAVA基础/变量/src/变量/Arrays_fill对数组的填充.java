package ����;

public class Arrays_fill���������� {
	public static void main(String[] args){
		int [] a =new int [5];
		int [] b =new int [5];
		
		// ���� ���� Arrays.fill ����   ǰ�滹�ü���  java.util.
		java.util.Arrays.fill(a,1);   //������ a ��� 1
		java.util.Arrays.fill(b,2,4,20);//��b[2] �� b[4] ��20���
		for(int i=0;i<a.length;i++)
			System.out.println(a[i]+" ");
		for(int i=0;i<b.length;i++)
			System.out.println(b[i]+" ");
	}
}
