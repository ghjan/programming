package _16;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

class Student implements Comparable<Student>{
	private String name;
	private int age;
	Student(String name,int age){
		this.name = name;
		this.age  = age;
	}
	
	public int compareTo(Student s){
		System.out.println("���ڱȽ��ַ�����С");
		int num = this.age - s.age;
		if(num==0){
			return this.name.compareTo(s.name);
		}
		return num;
	}
	
	public int hashCode(){
		System.out.println("���ڵ���hashCode");
		return name.hashCode()+age*12;
	}
	
	public boolean equals(Object obj){
		if(obj instanceof Student){
			Student s = (Student)obj;
			System.out.println(s.getName()+"   ���ڵ���equals");
			
			return this.name.equals(s.name) && this.age == s.age; 
		}
		throw new ClassCastException("���Ͳ�ƥ��");
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
public class map_3_test {
	public static void main(String[] args) {
		HashMap<Student,String> hm = new HashMap<Student,String>();
		hm.put(new Student("zhan1",20), "beijing");
		hm.put(new Student("zhan3",22), "nanjing");
		hm.put(new Student("zhan4",24), "wuhan");
		hm.put(new Student("zhan1",20), "shanghai");
		
		//��һ��ȡ����ʽ  keySet
		Set<Student> keyset = hm.keySet();
		System.out.println("1");
		for(Iterator<Student> it = keyset.iterator();it.hasNext();){
			System.out.println("2");
			Student stu = it.next();
			System.out.println("3");
			String addr = hm.get(stu);
			System.out.println("4");
			System.out.println(stu.getName()+"   "+stu.getAge()+"    "+addr);
		}
		
		System.out.println();
		
		//�ڶ��ַ�ʽȡ��
		Set<Map.Entry<Student,String>> entryset = hm.entrySet();
		for(Iterator<Map.Entry<Student,String>> it = entryset.iterator();it.hasNext();){
			Map.Entry<Student, String> me = it.next();
			Student stu = me.getKey();
			String addr = me.getValue();
			System.out.println(stu.getName()+"----"+stu.getAge()+"----"+addr);
		}
		
	}
}
