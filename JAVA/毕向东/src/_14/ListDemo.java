package _14;

import java.awt.List;
import java.util.*;

/*
 * Collection
 * 		|--List;Ԫ��������ģ�Ԫ�ؿ����ظ�����Ϊ�ü�����ϵ������
 * 			|--ArrayList:�ײ�����ݽṹʹ�õ�������ṹ	�ص㣺��ѯ�ٶȿ죬������ɾ�ٶ���	�̲߳�ͬ��
 * 			|--LinkedList;�ײ�ʹ�õ�������ṹ	�ص㣺��ѯ�ٶ�����������ɾ�ٶȿ�
 * 			|--Vector:�ײ����������ݽṹ		�߳�ͬ��
 * 
 * 		|--Set;Ԫ���������(�����ȡ����˳��һ��һ��)��Ԫ�ز������ظ�
 * 			|--
 * 
 * List��
 * 		���з������������Բ����Ǳ�ķ������Ǹ���ϵ�����з���
 * 
 * ����
 * 		add();
 * 		addAll();
 * 
 * ɾ��
 * 		remove();
 * 
 * �ģ�
 * 		set();
 * 
 * �飺
 * 		get();
 * 		subList(from,to);
 * 		ListItrrator();
 * 
 * List�������еĵ�������ListIterator��Iterator�ӽӿ�
 * 
 * �ڵ���ʱ��������ͨ�����϶���ķ������������е�Ԫ��
 * ��Ϊ�ᷢ��ConcurrentModificationException�쳣
 * 
 * ���ԣ��ڵ���ʱ��ֻ���õ����ڵķ�������Ԫ��
 */
public class ListDemo {
	public static void main1(String[] args) {
		ArrayList al = new ArrayList();
		al.add("java1");
		al.add("java2");
		al.add("java3");
		
		System.out.println(al);
		//��ָ��λ�����Ԫ��
		al.add(1,"java0");
		System.out.println(al);
		
		//ɾ��ָ��λ��Ԫ��
		al.remove(2);
		System.out.println(al);
		
		al.set(1,"java3");
		System.out.println(al);
		
		//ͨ���Ǳ��ȡԪ��
		System.out.println(al.get(1));
		
		//��ȡ����Ԫ��
		for(int x = 0; x<al.size();x++){
			System.out.println(al.get(x));
		}
		
		for(Iterator it = al.iterator();it.hasNext();){
			System.out.println(it.next());
		}
		
		//ͨ��indexOf��ȡ�����λ��
		System.out.println(al.indexOf("java3"));
		
		java.util.List sub = al.subList(1, 3);
		System.out.println(sub);
	}
	public static void main(String[] args) {
		//��ʾ������
		ArrayList al = new ArrayList();
		al.add("java1");
		al.add("java2");
		al.add("java3");
		
		System.out.println(al);
		//�ڵ��������У�׼����ӻ���ɾ��Ԫ��
		
		for(ListIterator li = al.listIterator();li.hasNext();){
			Object obj = li.next();
			if(obj.equals("java2")){
				li.add("java9");
//				li.set("java00");//����ͬʱ��������
			}
			if(obj.equals("java1"))
				li.set("java00");
			
			if(obj.equals("java9"))//�Ҳ���
				li.set("java88");
		}
		
		/*for(Iterator it = al.iterator();it.hasNext();){
			Object obj = it.next();
			if(obj.equals("java2"))
//			al.add("java4");�ڵ���ʱ��������ͨ�����϶���ķ������������е�Ԫ��
				it.remove();
			System.out.println("obj  "+obj);
		}*/
		
		System.out.println(al);
		
	}
}
