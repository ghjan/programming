package ����;


public class ���鸴�� {
	public static void main(String [] args){
		int [] a ={1,2,3,4,5};
		int [] b={11,12,13,14,15};
		//������b ��ֵ���Ƶ� a ��
		System.arraycopy(b, 1, a, 2, 3);	// �� b[1]��ʼ�� 3������     ���Ƶ�     ��  a[2]��ʼ  �ĺ�����������
		System.out.println("����֮���ֵ");
		for(int i=0;i<a.length;i++){
			System.out.println(a[i]);
		}
	}
}
