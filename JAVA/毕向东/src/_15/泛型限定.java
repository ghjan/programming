package _15;
/*
 *     ?  ͨ�����Ҳ�������Ϊռλ��
 *     ���͵��޶��� ? extends E:���Խ���E���ͻ���E�������͡�������
 *     ? super��E ���Խ���E���ͻ���E�������͡�������
 */
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

class NameCompare implements Comparator<Person>{//�Ƚ���
	public int compare(Person p1,Person p2){
		return p1.getName().compareTo(p2.getName());
	}
}
public class �����޶� {
	public static void main(String[] args) {
		// ? extends E:���Խ���E���ͻ���E�������͡�������
		//ArrayList(Collection<? extends E> c) ����һ������ָ�� collection ��Ԫ�ص��б���ЩԪ���ǰ��ո� collection �ĵ������������ǵ�˳�����еġ� 
		ArrayList<Person> al = new ArrayList<Person>();//Person��������
		al.add(new Person("��"));
		
		al.add(new Students("bbb"));
		al.add(new Students("ccc"));
		al.add(new Students("aaa"));
		for(Iterator<Person> it = al.iterator();it.hasNext();){//Person��������
			System.out.println(it.next().getName());
		}
//		printDemo(al);
		
		
		
		//? super��E ���Խ���E���ͻ���E�������͡�������
		//TreeSet(Comparator<? super E> comparator)    ����һ���µĿ� TreeSet��������ָ���Ƚ�����������
		TreeSet<Work> ts = new TreeSet<Work>(new NameCompare());//Work��������
		
		ts.add(new Work("--ccc"));
		ts.add(new Work("--aaa"));
		ts.add(new Work("--bbb"));
		
		for(Iterator<Work> it = ts.iterator();it.hasNext();){//Work��������
			System.out.println(it.next().getName());
		}
		
		TreeSet<Students> ts1 = new TreeSet<Students>(new NameCompare());
		
		ts1.add(new Students("++bbb"));
		ts1.add(new Students("++ccc"));
		ts1.add(new Students("++aaa"));
		
		for(Iterator<Students> it = ts1.iterator();it.hasNext();){//Work��������
			System.out.println(it.next().getName());
		}

		
	}
	//�����޶���  ������������޶���ֻ�޶����� ����ΪPerson �� ����Person����
	public static void printDemo(ArrayList<? extends Person> al){
		for(Iterator<? extends Person>it = al.iterator();it.hasNext();){
			System.out.println(it.next().getName());
		}
	}
//	public static void printDemo2(TreeSet<? super Work> ts){
//		for(Iterator<? super Work> it = ts.iterator();it.hasNext()){
//			System.out.println(it.next().get);
//		}
//	}
}
class Person{
	private String name ;
	Person(String name){
		this.name = name;
	}
	public String getName(){
		return name;
	}
}
class Students extends Person{
	Students(String name) {
		super(name);
	}
}
class Work extends Person{
	Work(String name) {
		super(name);
	}
}

