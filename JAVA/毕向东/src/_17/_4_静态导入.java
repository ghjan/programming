package _17;

import java.util.Arrays;
import static java.util.Arrays.*;//�������Arrays������е����о�̬��Ա
import static java.lang.System.*;
/*
 * ����������ʱ����Ҫ�ƶ�����İ���
 * ����������ʱ���ƶ����������Ķ��������
 */
public class _4_��̬���� {
	public static void main(String[] args) {
		int[] arr = {3,4,1};
		
		Arrays.sort(arr);
		System.out.println(Arrays.toString(arr));
		System.out.println(Arrays.binarySearch(arr, 3));
		
		sort(arr);
		System.out.println(Arrays.toString(arr));//���Arrays������ʡ����ΪObject��Ҳ��
		System.out.println(binarySearch(arr, 3));
		
		out.println("haha");//import static java.lang.System.*;
		
	}
}
