package ����;
import java.util.Arrays;

// ����������鳤��     ��ͬλ�õ�Ԫ��   ��һ�� ��ô�������������

public class ����ıȽ� {
	public static void main(String [] args){
		int [] a =new int [5];
		int [] b =new int [5];
		java.util.Arrays.fill(a, 1);
		java.util.Arrays.fill(b,2,4,2);// �� 2 �����
		if(Arrays.equals(a, b))
			System.out.print("���\n");
		else
			System.out.print("�����\n");
		
		System.out.println(Arrays.equals(a, b));
	}
}
