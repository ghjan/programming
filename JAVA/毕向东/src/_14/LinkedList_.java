package _14;

import java.util.LinkedList;

/*
 * LinkedList�����з���
 * addFirst();
 * addLast();
 * 
 * ��ȡԪ�أ�����Ԫ�ر�ɾ�������������û��Ԫ�أ�������쳣
 * removeFirst();
 * removeLast();
 * 
 * JDK1.6�����˴��淽��
 * offerFirst();�ڴ��б�Ŀ�ͷ����ָ����Ԫ�ء�
 * offerLast(); �ڴ��б�ĩβ����ָ����Ԫ�ء�
 * 
 * 
 * ��ȡԪ�أ�����ɾ��Ԫ�ء����������û��Ԫ�أ�����null
 * peekFirst() ��ȡ�����Ƴ����б�ĵ�һ��Ԫ�أ�������б�Ϊ�գ��򷵻� null��
 * peekLast() ��ȡ�����Ƴ����б�����һ��Ԫ�أ�������б�Ϊ�գ��򷵻� null��
 * 
 */
public class LinkedList_ {
	public static void main1(String[] args) {
		LinkedList link = new LinkedList();
		link.addFirst("java1");//��ͷ������
		link.addFirst("java2");
		link.addFirst("java3");
		System.out.println(link);
		
		link.addLast("dong");//��β������
		System.out.println(link);
		
		System.out.println(link.getFirst());//��ȡͷ��
		System.out.println(link.getLast());//��ȡβ��
		
		System.out.println(link.removeFirst());//��ȡԪ�أ�����ɾ�����Ԫ��
		System.out.println(link.removeFirst());
		
		System.out.println("size = "+link.size());
	}
	public static void main(String[] args) {
		LinkedList link = new LinkedList();
		link.addFirst("java1");//��ͷ������
		link.addFirst("java2");
		link.addFirst("java3");
		System.out.println(link);
		//ģ�µ�����
//		while(!link.isEmpty()){//Ϊ�շ���1
//			System.out.println(link.removeFirst());
//		}
		while(!link.isEmpty()){//Ϊ�շ���1
			System.out.println(link.removeLast());
		}
		
	}
}
