package _13;
/*
 * ��ȡ�����ַ����������ͬ���Ӵ�
 * 
 * ����������������ܴ���ͬʱ���������������ϵ������ͬ�Ӵ���ֻ�ܷ��ؿ�ǰ������Ӵ�����������ʵҪ��Ҳ�ܺøģ���Ҫ��˼��
 */
public class String_��ϰ3 {
	public static void main(String[] args) {
		String s1 = "dfsahellodongfdsjoa";
		String s2 = "helloaswedong";
		System.out.println("����Ӵ�"+getMaxSubString(s1, s2));
	}
	
	public static String getMaxSubString(String s1,String s2){
		String max,min;
		max = (s1.length()>s2.length()?s1:s2);
		min = (max == s1)?s2:s1;
		
		for(int i = 0; i<min.length(); i++){
			for(int j = min.length()-i , z = 0; j<=min.length();j++,z++){
				String temp = min.substring(z,j);
				System.out.println(temp);
				if(max.contains(temp))
					return temp;
			}
		}
		return "";
	}
}
