package _17;

import java.util.*;
/*
 * static <T> List<T>  asList(T... a)   ����һ����ָ������֧�ֵĹ̶���С���б�
 * 
 * ��������е�Ԫ�ض��Ƕ�����ô��ɼ���ʱ�������е�Ԫ�ؾ�ֱ��ת�ɼ����е�Ԫ��
 * ��������е�Ԫ�ض��ǻ����������ͣ���ô�ͻὫ��������Ϊ�����е�Ԫ�ش���
 */
public class _2_Arrays {
	public static void main(String[] args) {
//		int[] arr = {2,3,4};
//		System.out.println(Arrays.toString(arr));
		String[] arr = {"abc","cc","dong"};//�����е�Ԫ�ض��Ƕ���
		List<String> list = Arrays.asList(arr);//��������List
		/*
		 * �����ݱ��List������ʲô�ô�
		 * ����ʹ�ü��ϵ�˼��ͷ��������������е�Ԫ��
		 * contains
		 * get
		 * indexOf()
		 * subList();
		 * ע�⣺�������ɼ��ϣ�������ʹ�ü��ϵ���ɾ����
		 * ��Ϊ���鳤���ǹ̶���
		 */
		System.out.println(list.contains("dong"));
		System.out.println(list);
		

		int[] num = {2,4,5};//�����еĶ��ǻ�����������
		List<int[]> lis = Arrays.asList(num);
		System.out.println(lis);
		
		Integer[] nums = {2,4,5};//�Զ�װ�䣬�൱�������еĻ��Ƕ���
		List<Integer> li = Arrays.asList(nums);
		System.out.println(li);
		
	}
}
