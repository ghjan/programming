package _14;

import java.util.LinkedList;

/*
 * ʹ��LinkedListģ��һ����ջ���߶������ݽṹ
 */
class Queue{
	private LinkedList link;
	
	Queue(){
		link = new LinkedList();
	}
	
	public void add(Object obj){
		link.add(obj);//��ָ��Ԫ����ӵ����б�Ľ�β��
	}
	
	public Object queue(){
		return link.removeFirst();
	}
	
	public Object stack(){
		return link.removeLast();
	}
	
	public boolean isNull(){
		return link.isEmpty();
	}
}

public class LinkedList_test {
	public static void main(String[] args) {
		Queue q = new Queue();
		q.add("java1");//��ͷ������
		q.add("java2");
		q.add("java3");
		
		//ģ�����
//		while(!q.isNull())
//		System.out.println(q.queue());
		
		while(!q.isNull()){
			System.out.println(q.stack());
		}
		
	}
}
