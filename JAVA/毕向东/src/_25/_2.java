package _25;

import java.util.TreeSet;

public class _2 {
	public static void main1(String[] args) {
		String str = "���ҡ�����Ҫ����ҪҪ����ѧѧѧ�������";
		
		str = str.replaceAll("��+", "");//ȥ����
		System.out.println(str);
		
		str = str.replaceAll("(.)\\1+", "$1");//ɾ������		.���������ַ�	\1�����һ��ʡ�����Ҫ����ת���	$1Ҳ�����һ���
		System.out.println(str);
	}
	public static void main2(String[] args) {
		//����С�����˳����
		String ip = "192.168.1.1 2.12.45.65 10.12.45.128 010.56.87.100";
		
		ip = ip.replaceAll("(\\d+)", "00$1");
		System.out.println(ip);
		
		ip = ip.replaceAll("0+(\\d{3})","$1");//�Ȳ鵽һ������0��ͷ���Һ�������������������ַ�����Ȼ�����滻Ϊ�����ַ���
												//�������û��3����������ǰ���0������0�������Ͳ����滻
		System.out.println(ip);
		
		String[]  arr = ip.split(" ");
		
		TreeSet<String> ts = new TreeSet<String>();
		for(String s : arr){//�����ַ���
			ts.add(s);
		}
		for(String s : ts){//��������
			System.out.println(s.replaceAll("0*(\\d+)", "$1"));
		}
	}
	/*
	 * ���ʼ���ַ����У��
	 */
	public static void main(String[] args) {
		String mail = "abc12@sina.com.cn";
		//��ͷΪa-zA-Z0-9_һ��������Ȼ����һ��@��Ȼ��a-zA-Z0-9һ��������Ȼ���� . ��Ȼ����a-zA-Zһ��������Ȼ���������������ظ�
		String reg = "[a-zA-Z0-9_]+@[a-zA-Z0-9]+(\\.[a-zA-Z]+)+";//��ȷƥ��
		reg = "\\w+@\\w+(\\.\\w+)+";//��̫��ȷ
		System.out.println(mail.matches(reg));
	}
}
