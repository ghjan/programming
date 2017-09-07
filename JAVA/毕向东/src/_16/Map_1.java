package _16;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

/*
 * Map���ϣ��ü��ϴ洢��ֵֵ�ԣ�
 * 
 * Map
 * 	|--Hashtable���ײ��ǹ�ϣ�����ݽṹ�������Դ���null��nullֵ���������߳�ͬ��
 * 	|--HashMap���ײ��ǹ�ϣ�����ݽṹ��������ʹ�� null ֵ�� null ��,��ͬ��
 * 	|--TreeMap���ײ��Ƕ��������ݽṹ���̲߳�ͬ�����������ڸ�map�����еļ���������
 * 
 * ��Set����
 * Set�ײ����ʹ����Map����
 */
public class Map_1 {
	public static void main(String[] args) {
		Map<String,String> map = new HashMap<String,String>();
		//���Ԫ��,���������ͬ�ļ�ֵ����ô����ӵ�ֵ��������ǰ��ֵ����������ǰ��ֵ
		map.put("01","zhangsan1");
		map.put("02","zhangsan2");
		map.put("03","zhangsan3");
		System.out.println(map);
		System.out.println(map.containsKey("01"));
		
		System.out.println("remove 02 :"+map.remove("02"));
		System.out.println("get 02 :"+map.get("02"));
		System.out.println(map);
		map.put("02","zhangsan2");
		
		//HashMap������ʹ�� null ֵ�� null ��
		map.put(null, "haha");
		System.out.println("get null   "+map.get(null));//����ͨ��get���������ķ���ֵ���ж�һ�����Ƿ����
		map.put("04", null);
		System.out.println("get 04   "+map.get("04"));//������ӳ���
		
		//��ȡmap����������ֵ
		Collection<String> coll = map.values();
		System.out.println(coll);
		
		System.out.println(map);
		
	}
}
