package _06;
class Person{
	//����ִ��
	private String name = "dong";//Ĭ�ϳ�ʼ��Ϊ   dong
	private int age;			//Ĭ�ϳ�ʼ��Ϊ     0
	
	//���ִ��
	Person(String name,int age){
		this.name = name;
		this.age  = age;
		System.out.println(name+"  "+ age);
	}
	//��������-----����ִ��
	{
		System.out.println(name+"  "+ age);
	}
	//�ڶ�ִ��
	static{
		System.out.println("����static�����");
	}
}
public class �������� {
	public static void main(String[] args) {
		new Person("cmd",20);
	}
}
/*	new Person("cmd",20);
 * 1��new ���� Person.class �����Ի����ҵ� person.class�ļ����ص��ڴ���
 * 2��ִ�и����е�static����飬�������ʼ��****************************************
 * 3���ڶ��ڴ��п��ٿռ䣬�����ڴ��ַ��
 * 4���ڶ��ڴ��н���������������ԣ�������Ĭ�ϳ�ʼ��*********************************
 * 5�������Խ�����ʾ��ʼ��*********************************************************
 * 6���Զ�����й��������ʼ��****************************************************
 * 7���Զ�����ж�Ӧ�Ĺ��캯����ʼ��************************************************
 * 8�����ڴ��ַ�������ڴ��е�P����
 */