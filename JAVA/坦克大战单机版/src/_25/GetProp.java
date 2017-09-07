package _25;

import java.io.IOException;
import java.util.Properties;

/**
 * ʹ�������ļ����������˵������ģʽ
 * @author ���
 *
 */
public class GetProp {
	private static Properties prop = new Properties();
	
	static{
		try {
			prop.load(GetProp.class.getClassLoader().getResourceAsStream("config/tank.properties"));
		} catch (IOException e1) {
			e1.printStackTrace();
		}
	}
	
	private GetProp(){}
	
	public static String getProp(String key){
		return prop.getProperty(key);
	}
	
}
