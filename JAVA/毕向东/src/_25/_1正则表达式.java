package _25;
/*
 * ������ʽ������һ������ı��ʽ
 * 		���ã�����ר�Ų����ַ���
 * 		�ص㣺��һЩ�ض��ķ�������ʾһЩ�������
 * 		�ô������Լ򻯶��ַ����ĸ��Ӳ���
 * 
 * �������
 * 1��ƥ�䣺String matches����
 * 
 * 
 */
public class _1������ʽ {
	public static void main(String[] args) {
		//qq();
		checkqq();
	}
	/*
	 * ��QQ�Ž���У��
	 * Ҫ��5~15 0���ܿ�ͷ��ֻ��������
	 */
	public static void qq(){
		String q = "a12345";
		int len = q.length();
		
		if(len>=5 && len<=15){
			if(!q.startsWith("0")){
				try {
					long l = Long.parseLong(q);
				} catch (NumberFormatException e) {
//					throw new NumberFormatException("���ַǷ��ַ�===");
					System.out.println("���ַǷ��ַ�===");
				}
				/*char[] arr = q.toCharArray();
				boolean flag = true;
				for(int x = 0;x<arr.length;x++){
					
					if(arr[x]<'0' || arr[x] >'9'){
						flag = false;
						break;
					}
				}
				if(flag)
					System.out.println("qq:"+q);
				else
					System.out.println("�Ƿ��ַ�");*/
			}
			else
				System.out.println("������0��ͷ");
		}
		else
		System.out.println("���ȴ���");
	}
	
	public static void checkqq(){
		String qq = "2a3314";
		boolean f = qq.matches("[0-9][1-9]{4,14}");
		if(f)
			System.out.println("qq:"+qq);
		else
			System.out.println("���Ϸ�");
	}
}
