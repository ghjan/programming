package _16;

import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

/*
 * "abcdabcdef"��ȡ���ַ�������ĸ���ֵĴ���
 * ϣ����ӡ��� �� a(1)c(2)-----
 * 
 * ˼·��
 * 1�����ַ���ת�����ַ����飬��ΪҪ��ÿһ����ĸ���в���
 * 2������һ��map���ϣ���Ϊ��ӡ�������ĸ��˳������ʹ��treemap����
 * 3�������ַ�����
 * 		��ÿһ���ַ���Ϊ��ֵȥ��map����
 * 		�����Χnull������ĸ��1����
 * 		������ز���null����ȡ�ô�������������Ȼ�󽫸���ĸ��������Ĵ�������map������
 * 4��ǿmap�����е����ݱ��ָ�����ַ�����ʽ����
 * 
 */
public class map_4_��ϰ {
	public static void main(String[] args) {
//		charCount("abcdabcd.dong");
		String s = charCount("abcdabcd.dong");
		System.out.println(s);
	}
	
	public static String charCount(String str){
		char[] chs = str.toCharArray();
		
		TreeMap<Character,Integer> tm = new TreeMap<Character,Integer>();
		
		for(int x=0;x<chs.length;x++){
			//���ݼ�ֵ���ַ���	��ȡֵ���ַ���Ӧ�Ĵ�����
			Integer value = tm.get(chs[x]);
			
			if(value==null)
				value = 0;;
			value++;//Ϊnull value = 1  ��Ϊ null ����  1
			
			tm.put(chs[x], value);
		}
		System.out.println(tm);
		//����һ���������������Դ����κζ���
		StringBuilder sb = new StringBuilder();
		
		/*��һ��ȡ��
		Set<Character> keyset = tm.keySet();
		for(Iterator<Character> it = keyset.iterator();it.hasNext();){
			char key = it.next();
			int value = tm.get(key);
			sb.append(key+"("+value+")");
		}*/
		//�ڶ���
		Set<Map.Entry<Character,Integer>> entryset = tm.entrySet();
		for(Iterator<Map.Entry<Character,Integer>> it = entryset.iterator();it.hasNext();){
			Map.Entry<Character,Integer> me = it.next();
			char key = me.getKey();
			int value = me.getValue();
			sb.append(key+"("+value+")");
		}
		
		return sb.toString();
	}
	
}
/*�� Character������ʵ�ֵĽӿڣ� 
Serializable, Comparable<Character> 

 */
