package _14;

import java.util.HashSet;
import java.util.Iterator;

/*
 * ������  ����  �˵����ֺ�����   
 * 
 * 				HashSet����α�֤Ԫ��Ψһ�Ե��أ�
 * 				��ͨ��Ԫ�ص�����������hasCode��equals����ɵ�
 * 				���Ԫ�ص�HashCodeֵ��ͬ���Ż����equals�����Ƿ�Ϊtrue
 * 				���Ԫ�ص�hashCodeֵ��ͬ���������equals
 */
//class Person{}		������Ѿ�������
public class HashSet�����Զ������ {
	public static void main(String[] args) {
		HashSet hs = new HashSet();
		hs.add(new Person("a",11));
		hs.add(new Person("b",12));
		hs.add(new Person("b",12));
//		hs.add(new Person("c",13));
		
		System.out.println("ɾ��Ԫ�أ�b,12");
		hs.remove(new Person("b",12));
		
		Iterator it = hs.iterator();
		while(it.hasNext()){
			Person p = (Person)it.next();
			System.out.println(p.getName()+"    "+p.getAge());
		}
		
	}
}
