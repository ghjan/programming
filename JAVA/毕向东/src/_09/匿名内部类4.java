package _09;
/*
 * ���⣺
 * ���û�и���ͽӿڻ��ܴ����ڲ���ô��
 * �𣺲�����û�и��࣬��������û�и��ࡣ����JAVA�С����κ��඼��Object�������
 */
//�������ǲ��ýӿ�   ��     �Լ�����ĸ���
public class �����ڲ���4 {
	public static void main(String[] args) {
		new Object(){
			void function(){
				System.out.println("hello");
			}
		}.function();
	}
}
