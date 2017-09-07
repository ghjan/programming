package _14;

import java.util.ArrayList;
import java.util.Iterator;

/*
 * ���Զ��������ΪԪ�ش浽ArrayList�����У���ȥ���ظ�Ԫ��
 * 
 * ˼·��
 * 1�����������������ݷ�װ���˶���
 * 2���������������˴���
 * 3��ȡ��
 * 
 * List�����ж�Ԫ���Ƿ���ͬ�����ݵ���Ԫ�ص�equals����
 * 
 */
class Person{
	private String name ;
	private int age;
	Person(String name,int age){
		this.name = name ;
		this.age = age;
	}
	
	public int hashCode(){
		System.out.println("�Զ�����hashCode   "+this.name);
		return name.hashCode()+age;//hashCode���ַ����ķ���
	}
	
	public boolean equals(Object obj){							//�ڵ���contains����ʱ�����Զ����ã����� equals����������дequals��Ĭ�ϵ���Object�е�equals����
		if(obj instanceof Person){
			Person p = (Person)obj;
			System.out.println("����Ĭ�ϵ���equals������\t "+this.name+"  ����   equals ��    "+p.name+"    �Ƚ�");
			
			return this.name.equals(p.name) && this.age == p.age;//equals���ַ�����equals
		}
		return false;
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
public class ArrayList_test2 {
	public static void main(String[] args) {
		ArrayList al = new ArrayList();
		al.add(new Person("��",11));
		al.add(new Person("��",12));
		al.add(new Person("��",13));
		al.add(new Person("��",11));
		al.add(new Person("��",12));
		
		al = singleElement(al);
		
		Iterator it = al.iterator();
		
		while(it.hasNext()){
			Person p = (Person)it.next();//it.next���ص���Object�ࡣ������Ҫ����Object���ࣨPerson�ࣩ�е����з�����getName���������ǿת
			System.out.println(p.getName()+"    "+p.getAge());
		}
		
	}
	public static ArrayList singleElement(ArrayList al){
		ArrayList newAl = new ArrayList();
		
		Iterator it = al.iterator();
		
		while(it.hasNext()){
			Object obj = it.next();
			if(!newAl.contains(obj)){
				newAl.add(obj);
			}
		}
		return newAl;
	}
	
	
}
