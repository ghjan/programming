package _13;
/*
 * ����һ���ַ�����    ĳһ���Ӵ��ĸ���
 */
public class String_��ϰ2 {
	public static void main(String[] args) {
		String s = " hello java xxx yyy xx xx yxy ";//��������ʱ��   xxx  ��һ���Ӵ������о������⣬����xxx��һ���Ӵ��������������ǲ����Ӵ�
		System.out.println(s.indexOf("xx"));
		System.out.println(getSubCount(s,"xx"));
	}
	
	static int getSubCount(String str,String sub){
		int index = 0;
		int count = 0;
		while((index = str.indexOf(sub, index))!= -1){
			count++;
			index = index + sub.length();
		}
		return count;
	}
}
