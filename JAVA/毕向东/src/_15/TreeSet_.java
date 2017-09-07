package _15;

import java.util.Iterator;
import java.util.TreeSet;

/*
 * Set�����򣬲������ظ�Ԫ��
 * 	|--HashSet�����ݽṹ�ǹ�ϣ���߳��Ƿ�ͬ����
 * 		|--��֤Ԫ��Ψһ�Ե�ԭ���ж�Ԫ�ص�hashCodeֵ�Ƿ���ͬ
 * 		|--�����ͬ����������ж�Ԫ�ص�equals�������Ƿ�Ϊtrue
 * 	|--TreeSet:���Զ�Set�����е�Ԫ�ؽ�������
 * 			   �ײ����ݽṹ�Ƕ�����
 * 			 ��֤Ԫ��Ψһ�Ե����ݣ�compareTo���� return 0��
 * 			
 * 			TreeSet����ĵ�һ�ַ�ʽ����Ԫ������߱��Ƚ���
 * 			Ԫ����Ҫʵ��Comparable�ӿڣ�����compareTo����
 * 			���ַ�ʽҲ��ΪԪ�ص���Ȼѭ��
 * 
 * 			TreeSet�ĵڶ�������ʽ
 * 			��Ԫ�������߱��Ƚ���ʱ�����߾߱��ıȽ��Բ�������Ҫ��
 * 			��ʱ����Ҫ�ü�������߱��ƽ���
 * 			�ڼ��ϳ�ʼ��ʱ�������˱ȽϷ�ʽ
 * 
 * ��ס������ʱ������Ҫ������ͬʱ��һ��Ҫ�жϴ�Ҫ����
 */
public class TreeSet_ {
	public static void main1(String[] args) {
		TreeSet ts = new TreeSet();
		
		ts.add("aaa");
		ts.add("bbb");
		ts.add("abc");
		ts.add("aab");
		
		for(Iterator it = ts.iterator();it.hasNext();){
			System.out.println(it.next());
		}
	}
	
	public static void main(String[] args) {
		TreeSet ts = new TreeSet();
		
		ts.add(new Student("��4",22));
		ts.add(new Student("��1",22));
		ts.add(new Student("��4",23));
		ts.add(new Student("��3",24));
		ts.add(new Student("��5",43));
		for(Iterator it = ts.iterator();it.hasNext();){
			Student s = (Student)it.next();
			System.out.println(s.getName()+"    "+s.getAge());
		}
	}
}
class Student implements Comparable{//�ýӿ�ǿ����ѧ���߱��Ƚ���
	private String name;
	private int age;
	
	Student(String name,int age){
		this.name = name ;
		this.age = age ;
	}
	
	public int compareTo(Object obj){				//��д  �ӿ� ��������ʹ֮�Ƚ���������
		if(!(obj instanceof Student))
			throw new RuntimeException("����ѧ������");
		Student s = (Student)obj;
		
		//System.out.println(this.name+"..."+this.age+"......compare......."+s.name+"..."+s.age);
		
		if(this.age > s.age ){
			return 1;
		}
		if(this.age == s.age)
			return this.name.compareTo(s.name);//���ְ���Ȼѭ������
		return -1;
		
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
}
