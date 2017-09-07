package _15;

import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

/*
 * ��ϰ�������ַ�����������
 * �ַ�������߱��Ƚ��ԣ��������ıȽϷ�ʽ��������Ҫ�ġ�
 * 
 * ���Ǿ�ֻ��ʹ�ñȽ���
 */
class StringLengthComparator implements Comparator{
	public int compare(Object o1,Object o2){
		Student s1 = (Student)o1;
		Student s2 = (Student)o2;
		
		/*if(s1.getName().length()>s2.getName().length())
			return 1;
		if(s1.getName().length() == s2.getName().length())
			return 0;*/
		int num = s1.getName().length() - s2.getName().length();
		
		if(num==0){
//			return s1.getName().compareTo(s2.getName());
			int n =  s1.getName().compareTo(s2.getName());
			
			if(n==0)
				return s1.getAge() - s2.getAge();
			
			return n;
		}
		return num;
	}
}
public class TreeSet3��ϰ {
	public static void main(String[] args) {
		TreeSet ts = new TreeSet(new StringLengthComparator());
		
		ts.add(new Student("��aaaaa",2));
		ts.add(new Student("��aaaaa",1));
		ts.add(new Student("��bbbb",3));
		ts.add(new Student("��ccc",4));
		ts.add(new Student("��ddddddd",5));
		for(Iterator it = ts.iterator();it.hasNext();){
			Student s = (Student)it.next();
			System.out.println(s.getName()+"    "+s.getAge());
		}
	}
}
