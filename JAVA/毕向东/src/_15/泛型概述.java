package _15;
/*
 * ���ͣ�JDK1.5�汾�Ժ���ֵ������ԣ����ڽ����ȫ���⣬��һ�����Ͱ�ȫ����
 * �ô���
 * 		1��������ʱ�ڳ�������ClassCastException��ת�Ƶ��˱���ʱ��
 * 			�����ڳ���Ա������⣬����������������٣���ȫ
 * 		2,������ǿ������ת���鷳
 */
import java.util.ArrayList;
import java.util.Iterator;

public class ���͸��� {
	public static void main(String[] args) {
		ArrayList<String> al = new ArrayList<String>();
		al.add("abc1");
		al.add("abc3");
		al.add("abc2");
//		al.add(4);//�Զ�װ��  al.add(new Integer(4));
		
//		for(Iterator it = al.iterator();it.hasNext();){
//			String s = (String )it.next();
//			System.out.println(s+":"+s.length());
//		}
		for(Iterator<String> it = al.iterator();it.hasNext();){
			String s = it.next();
			System.out.println(s+":"+s.length());
		}
		
	}
}
