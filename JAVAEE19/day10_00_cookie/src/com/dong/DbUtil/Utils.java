package com.dong.DbUtil;

import java.util.HashMap;
import java.util.Map;

import com.dong.entity.Beauty;

//����Ҫ�������ݿ⵫��Ϊ�˼�㣬��ֱ�Ӹ�ֵ
public class Utils {
	private static Map<String,Beauty> beauty = new HashMap<String,Beauty>();
	
	static {
		beauty.put("1", new Beauty("����ӱ","10000"));
		beauty.put("2", new Beauty("���Ȼ�","1000"));
		beauty.put("3", new Beauty("��ɯ","12000"));
		beauty.put("4", new Beauty("����","5000"));
		beauty.put("5", new Beauty("֣ˬ","6000"));
	}
	
	public static Map<String,Beauty> findAllBeauty(){
		return beauty;
	}
	
	//���ݼ�ֵ   ��������
	public static Beauty findBeauty(String id){
		return beauty.get(id);
	}
}
