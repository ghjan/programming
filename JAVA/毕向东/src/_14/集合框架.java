package _14;
/*
 * add �����Ĳ���������Object���Ա��ڽ����κ����Ͷ���
 * 
 * �����д洢�Ķ��Ƕ�������ã���ַ��
 * 
 * ʲô�µ�������
 * ��ʵ���Ǽ��ϵ�ȡ��Ԫ�صķ�ʽ
 * 
 */
import java.util.ArrayList;
import java.util.Iterator;

public class ���Ͽ�� {
	public static void main1(String[] args) {
		//����һ������������ʹ��Collection�ӿڵ����࣬ArrayList
		ArrayList a1 = new ArrayList();
		//���Ԫ��
		a1.add("java1");
		a1.add("java2");
		a1.add("java3");
		a1.add("java4");
		//��ӡ����
		System.out.println(a1);
		//2.��ȡ���������ϳ���
		//System.out.println("size:"+a1.size());
		
		//3.ɾ��Ԫ��
		a1.remove("java2");
		System.out.println(a1);
//		a1.clear();//�������
//		System.out.println(a1);
		
		//4.�ж�Ԫ��
		System.out.println("java3�Ƿ���ڣ�"+a1.contains("java3"));
		
		System.out.println("�����Ƿ�Ϊ�գ�"+a1.isEmpty());
	}
	public static void main2(String[] args) {
		ArrayList al1 = new ArrayList();
		al1.add("java1");
		al1.add("java2");
		al1.add("java3");
		al1.add("java4");
		
		ArrayList al2 = new ArrayList();
		al2.add("java1");
		al2.add("java2");
		al2.add("java5");
		al2.add("java6");
		
		al1.retainAll(al2);//al1��al2ȡ����������retain����
		System.out.println(al1);
		System.out.println(al2);
		
		al1.removeAll(al2);//al1 ��ȥ  al2������Ԫ�أ����оͼ���û�оͲ�����
		System.out.println(al1);
		System.out.println(al2);
	}
	public static void main(String[] args) {
		ArrayList al = new ArrayList();
		al.add("java1");
		al.add("java2");
		al.add("java3");
		al.add("java4");
		
//		Iterator it = al.iterator();//��ȡ������������ȡ�������е�Ԫ��
//
//		while(it.hasNext()){//boolean	hasNext() �������Ԫ�ؿ��Ե������򷵻� true��
//			System.out.println(it.next());
//		}
		for(Iterator it = al.iterator();it.hasNext();)
			System.out.println(it.next());
		
		
		
		
	}
	
}
