package _17;
/*
 * �ɱ������
 * ��ʵ������������ļ�д��ʽ
 * ����ÿһ�ζ��ֶ������������
 * 
 */
public class _3_�ɱ���� {
	public static void main(String[] args) {
		show(3,3,4);
		show(3,3,4,3);
		show(3);
	}
	public static void show(int...arr){//�ɱ����
		int len = arr.length;
		while(len>0){
			System.out.print(arr[--len]);
		}
		System.out.println();
	}
	public static void show1(String s ,int...arr){//ע��ɱ����һ��Ҫ���������
		
	}
	public static void show1(int s ,String...arr){//ע��ɱ����һ��Ҫ���������
		
	}
}
