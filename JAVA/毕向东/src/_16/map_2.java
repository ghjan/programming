package _16;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

/*
 * mapȡ����ʽ�����֣�
 * 1��keySet����map�����еļ�ֵ���뵽Set���ϣ���ΪSet�߱������������Կ��Ե�����ʽȡ�����еļ���
 * 			    �ٸ���get��������ȡÿһ������Ӧ��ֵ
 * 
 * 			Map���ϵ�ȡ��ԭ����map����ת��set���ϣ���ͨ��set�����еĵ�����ȡ��
 * 2��Set<Map.Entry<k,v>> entrySet����map�����е�ӳ���ϵ���뵽��Set�����У��������ϵ���������;���Map.Entry
 * 2��
 */
public class map_2 {
	public static void main(String[] args) {
		Map<String,String> map = new HashMap<String,String>();
		map.put("02","zhangsan2");
		map.put("03","zhangsan2");
		map.put("01","zhangsan1");
		System.out.println(map);
		//�Ȼ�ȡmap�����е����м���Set����
		Set<String> keyset = map.keySet();//��ֵ��String���;���String
		//����Set���ϣ��Ϳ��Ի�ȡ�������
		for(Iterator<String> it = keyset.iterator();it.hasNext();){
			String key = it.next();
			String value = map.get(key);
			System.out.println(value);
		}
	}
	public static void main2(String[] args) {
		Map<String,String> map = new HashMap<String,String>();
		map.put("02","zhangsan2");
		map.put("03","zhangsan3");
		map.put("01","zhangsan1");
		//��map�����е�ӳ���ϵȡ��������Set����
		Set<Map.Entry<String,String>> entryset = map.entrySet();
		
		for(Iterator<Map.Entry<String,String>> it = entryset.iterator();it.hasNext();){
			Map.Entry<String,String> me = it.next();
			String key = me.getKey();
			String value = me.getValue();
			System.out.println(key+"         "+value);
		}
		
	}
}
