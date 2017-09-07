package _13;
/*
 * StringBuffer���ַ���������
 * 
 * ��һ������
 * 1�����ҳ����ǿ��Ա仯�ġ�
 * 2������ֱ�Ӳ��������������
 * 3�����ջ�ͨ��toString ��������ַ���
 * CURD  	create update read delete
 * 
 * 1.�洢
 * 		StringBuffer append()��ָ��������Ϊ������ӵ�ĩβ
 * 		StringBuffer insert(index,����);���Խ����ݲ��뵽ָ��indexλ��
 * 
 * 2.ɾ��
 * 		StringBuffer delete(int start, int end)    �Ƴ������е����ַ����е��ַ��� 
 * 		StringBuffer deleteCharAt(int index)  �Ƴ�������ָ��λ�õ� char�� 
 * 3.��ȡ
 * 		 char charAt(int index) ���ش�������ָ���������� char ֵ�� 
 * 		 int indexOf(String str) ���ص�һ�γ��ֵ�ָ�����ַ����ڸ��ַ����е������� 
         int indexOf(String str, int fromIndex) ��ָ������������ʼ�����ص�һ�γ��ֵ�ָ�����ַ����ڸ��ַ����е�������
         int length();
         String substring(int start,int end)
 * 4.�޸�
 * 		StringBuffer replace(int start, int end, String str)  ʹ�ø��� String �е��ַ��滻�����е����ַ����е��ַ���
 * 		void setCharAt(int index, char ch)      ���������������ַ�����Ϊ ch��  
 * 5.��ת
 * 		 StringBuffer reverse() �����ַ��������䷴ת��ʽȡ����
 * 6.
 *  	 void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)  ���ַ��Ӵ����и��Ƶ�Ŀ���ַ����� dst�� 
 * 
 * JDK 1.5 �汾֮�����StringBuilder();
 * 
 * StringBuffer���߳�ͬ��
 * StringBuilder���̲߳�ͬ��
 * 
 * �Ժ󿪷�������ʹ��StringBuilder
 * 
 *     public String toString() {
        return getClass().getName() + "@" + Integer.toHexString(hashCode());
    }
 * 
 */
public class Stringbuffer {
	public static void main(String[] args) {
		StringBuffer sb = new StringBuffer();
		sb.append("abc").append(true).append(111);
		sb.insert(1, "��");
		System.out.println(sb);
		
		sb.delete(1, 2);//ɾ���Ǳ� 1 --  2 ֮����������ǰ���ͷ��������β����
		System.out.println(sb);
		
		sb.deleteCharAt(0);//ɾ��0���ַ�
		System.out.println(sb);
		
		sb.delete(0, sb.length());
		System.out.println(sb+"�����");
		
		sb.append("0123456");
		System.out.println(sb);
//		sb.replace(1,4,"hello dong");//���
//		System.out.println(sb);
		sb.setCharAt(2, '��');
		System.out.println(sb);
		
		sb.reverse();
		System.out.println(sb);
		
	}
}
