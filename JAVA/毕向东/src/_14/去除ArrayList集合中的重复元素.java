package _14;

import java.util.ArrayList;
import java.util.Iterator;

public class ȥ��ArrayList�����е��ظ�Ԫ�� {
	public static void main(String[] args) {
		ArrayList al = new ArrayList();
		
		al.add("java1");
		al.add("java2");
		al.add("java1");
		al.add("java3");
		al.add("java2");
		System.out.println(al);
		
		//�ڵ���ʱѭ����nextʹ��һ�Σ���Ҫ��hasNext�ж�һ��
//		Iterator it = al.iterator();
//		while(it.hasNext()){
//			System.out.println(it.next());
//		}
		
		al = singleElement(al);
		System.out.println(al);
	}
	
	public static ArrayList singleElement(ArrayList al){
		//����һ����ʱ����
		ArrayList newAl = new ArrayList();
		
		Iterator it = al.iterator();//��ȡ������������ȡ��Ԫ��
		
		while(it.hasNext()){
			Object obj = it.next();
			
			if(!newAl.contains(obj)){// boolean contains(Object o) ������б��а���ָ����Ԫ�أ��򷵻� true 
				newAl.add(obj);
			}
		}
		return newAl;
	}
}
