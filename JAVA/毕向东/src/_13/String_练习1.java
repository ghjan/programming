package _13;

public class String_��ϰ1 {
	public static void main(String[] args) {
		//��ȥ�ַ������˿ո�,ʵ��trim����
		String s = "   hello java   ";
		System.out.println(trimm(s));
		
		//���ַ�����ת
		System.out.println(convert(s));
	}

	public static String trimm(String s){	//��ȥ�ַ������˿ո�,ʵ��trim����
		int start = 0;
		int end = s.length()-1;
		while(s.charAt(start) == ' ')
			start++;
		while(s.charAt(end) == ' ')
			end--;
		return s.substring(start,end+1);
	}
	
	public static String convert(String s){
		char[] arr = s.toCharArray();
		int start = 0;
		int end = s.length()-1;
		for(;start<end;start++,end--){
			swap(arr,start,end);
		}
		return new String(arr);
	}
	
	public static void swap(char[] arr,int a,int b){
		char t = arr[a];
		arr[a] = arr[b];
		arr[b] = t;
	}
	
}
