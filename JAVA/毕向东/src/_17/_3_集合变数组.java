package _17;

import java.util.*;
/*
 * Collection�ӿ��е�toArray����
 */
public class _3_���ϱ����� {
	public static void main(String[] args) {
		ArrayList<String> al = new ArrayList<String>();
		al.add("abc1");
		al.add("abc2");
		al.add("abc3");
		
		String[] arr = al.toArray(new String[0]);
		System.out.println(Arrays.toString(arr));
		
		String[] arr3 = al.toArray(new String[al.size()]);
		System.out.println(Arrays.toString(arr3));
		
		String[] arr2 = al.toArray(new String[5]);
		System.out.println(Arrays.toString(arr2));
		
	}
}
