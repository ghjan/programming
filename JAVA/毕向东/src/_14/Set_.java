package _14;

import java.util.HashSet;
import java.util.Iterator;

/*
 * 		|--Set;Ԫ���������(�����ȡ����˳��һ��һ��)��Ԫ�ز������ظ�
 * 			|--HashSet���ײ����ݽṹ�ǹ�ϣ��
 * 				HashSet����α�֤Ԫ��Ψһ�Ե��أ�
 * 				��ͨ��Ԫ�ص�����������hasCode��equals����ɵ�
 * 				���Ԫ�ص�HashCodeֵ��ͬ���Ż����equals�����Ƿ�Ϊtrue
 * 				���Ԫ�ص�hashCodeֵ��ͬ���������equals
 * 
 * 				ע�⣬�����ж�Ԫ���Ƿ���ڣ��Լ�ɾ���������ķ���ʱԪ�ص�hashCode��equals����
 * 
 * 			|--TreeSet��
 * 
 * Set���ϵĹ��ܺ�Collection��һ�µ� 
 * 
 */
class Demo{
	
}
class HashSetDemo{
	public int hashCode(){
		System.out.println("�Զ���hashCode");
		return 60;//ʮ��������	3c
	}
}
public class Set_ {
	public static void main1(String[] args) {
		System.out.println(new Demo());
		System.out.println(new Demo());
		System.out.println(new HashSetDemo());
	}
	public static void main(String[] args) {
		HashSet hs = new HashSet();
		
		System.out.println(hs.add("java1"));//�����˷���  true
		System.out.println(hs.add("java1"));//û�д��뷵��false
		hs.add("java2");
		hs.add("java2");
		hs.add("java3");
		hs.add("java88");//Set;Ԫ���������(�����ȡ����˳��һ��һ��)
		hs.add("java100");
		
		Iterator it = hs.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}
		
	}
	
}
