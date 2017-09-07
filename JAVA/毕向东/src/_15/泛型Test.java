package _15;

import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

public class ����Test {
	public static void main(String[] args) {
		TreeSet<String> ts = new TreeSet<String>(new LenComparator());
		
		ts.add("aaa");
		ts.add("dd");
		ts.add("b");
		ts.add("cccc");
		
		for(Iterator<String> it = ts.iterator();it.hasNext();){
			System.out.println(it.next());
		}
		
		System.out.println(new Integer(123));//��123�����������   ����˶��󡣿���ʹ�� Integer����ķ���-----
		/*   
		 *  public Integer(int value) {
        		this.value = value;}		���صľ��Ǵ�������  int ������
		 */
	}
}
class LenComparator implements Comparator<String>{
	public int compare(String o1,String o2){
//		int num = new Integer(o1.length()).compareTo(new Integer(o2.length()));compareTo(Integer anotherInteger) �������ϱȽ����� Integer ���� 
        
		int num = o1.length() - o2.length();
		
		if(num == 0)
			return o1.compareTo(o2);
		return num;
	}
}
