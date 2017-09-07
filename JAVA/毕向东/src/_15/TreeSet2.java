package _15;

import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

/* TreeSet�ĵڶ�������ʽ:
 * 
 * ��Ԫ�������߱��Ƚ��ԣ����߾߱��ıȽ��Բ�������Ҫ��
 * ��ʱ��Ҫ����������߱��Ƚ���
 * ������Ƚ��������Ƚ���������Ϊ�������ݸ�TreeSet���ϵĹ��캯��
 *  
 * ���������򶼴���ʱ���ԱȽ���Ϊ��
 * 
 * ����һ���࣬ʵ��Comparator�ӿڣ�����compare����
 * 
 */
public class TreeSet2 {
	public static void main(String[] args) {
		TreeSet ts = new TreeSet(new MyCompare());
		
		ts.add(new Student("��1",22));
		ts.add(new Student("��1",23));
		ts.add(new Student("��5",43));
		ts.add(new Student("��4",22));
		for(Iterator it = ts.iterator();it.hasNext();){
			Student s = (Student)it.next();
			System.out.println(s.getName()+"    "+s.getAge());
		}
	}
}
class MyCompare implements Comparator{
	public int compare(Object o1,Object o2){
		Student s1 = (Student)o1;
		Student s2 = (Student)o2;
		
		int num = s1.getName().compareTo(s2.getName());//�ַ�����Ȼ˳��Ƚ�
		
		if(num==0){
			return s1.getAge()-s2.getAge();
		}
		return num;
	}
}
