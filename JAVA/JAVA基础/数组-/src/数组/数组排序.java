package ����;

import java.util.Arrays;

public class �������� {

	public static void main(String[] args) {
		int [] a={5,4,2,6,7};
		int [] b={9,88,65,35};
		Arrays.sort(a, 1, 4);		//  ע��  ������� ������ ����		�� 1 ��4
		Arrays.sort(b);			//  ���Ӳ���Ĭ�� ȫ������
		for(int i=0;i<a.length;i++)
			System.out.println(a[i]);
		for(int i=0;i<b.length;i++)		//  ����� C ��һ��  �� for �� i ���Զ�������
			System.out.println(b[i]);
	}

}
