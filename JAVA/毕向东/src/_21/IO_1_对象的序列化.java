package _21;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class IO_1_��������л� {
	public static void main(String[] args) throws Exception {
		write();
		read();
	}
	public static void write() throws IOException{
		ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("E:\\programming\\JAVA\\�����ļ�\\1.txt"));
		oos.writeObject(new Person("dong", 20,100,"China"));
		oos.writeObject(new Person("zhang",21,111,"China"));
		oos.writeObject(new Person("lisi", 22,122,"China"));
		oos.writeObject(new Person("wang", 24,133,"China"));
		oos.close();
	}
	public static void read() throws IOException, Exception{
		ObjectInputStream ois = new ObjectInputStream(new FileInputStream("E:\\programming\\JAVA\\�����ļ�\\1.txt"));//������ָ�� InputStream ��ȡ�� ObjectInputStream
		for(int i=0;i<4;i++){
			Person p = (Person)ois.readObject();//ÿ��read֮��   �Զ�������һ��Person����
			System.out.println(p);
		}
		ois.close();
	}
}
class Person implements Serializable{
	private static final long serialVersionUID = 100L;//������仰�ٸı�����Ҳ�ܶ�ȡ����

	private String name;
	private int age;
	private static int a;//ע�⣺��̬���ܱ����л�
	private transient String country;//����뵽�Ǿ�̬�ĳ�Ա��Ҳ�����л����ͼ���transient�ؼ���
	Person(String name,int age,int a,String country){
		this.name = name;
		this.age = age;
		this.a = a;
		this.country = country;
	}
	@Override
	public String toString() {
		return name+"    "+age;
	}
}
class Person2 implements Serializable{
	private static final long serialVersionUID = 100L;

	private String name;
	private int age;
	Person2(String name,int age){
		this.name = name;
		this.age = age;
	}
	@Override
	public String toString() {
		return name+"    "+age;
	}
}