package _17;

import java.util.*;

public class _1_Collections {
	public static void main(String[] args) {
		List<String> list = new ArrayList<String>();
		
		list.add("bbb");
		list.add("aa");
		list.add("aa");
		list.add("dddd");
		list.add("z");
		list.add("cccc");
		System.out.println(list);
		
		Collections.sort(list);
		System.out.println(list);
		System.out.println("����Ԫ�ؽǱ�"+Collections.binarySearch(list, "z"));//����Ԫ�ؽǱ�

		Collections.sort(list,new Comparalen());//�Զ���Ƚ����Ƚ�
		System.out.println(list);
		
		System.out.println(Collections.max(list));//�������Ԫ��   ����������
		System.out.println(Collections.max(list,new Comparalen()));
		
		Collections.replaceAll(list, "aa", "qq");//�滻
		System.out.println(list);
		Collections.reverse(list);//����Ԫ�ط�ת
		System.out.println(list);
	}
}
//�����Ƚ���
class Comparalen implements Comparator<String>{

	@Override
	public int compare(String o1, String o2) {
		return o1.length() - o2.length();
	}
	
}
