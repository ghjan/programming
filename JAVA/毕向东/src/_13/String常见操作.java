package _13;

import javax.swing.plaf.synth.SynthSeparatorUI;

/*
 * 1����ȡ
 * 		1.1   int length()��ȡ����
 * 		1.2   char At(int index)	����ָ���������� char ֵ��
 * 		1.3   int indexOf(int ch) ����ָ���ַ��ڴ��ַ����е�һ�γ��ִ���������
 * 			  int indexOf(int ch, int fromIndex) �����ڴ��ַ����е�һ�γ���ָ���ַ�������������ָ����������ʼ������
 * 			  int indexOf(String str)  ����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ���������
 * 			  int indexOf(String str, int fromIndex) ����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ�����������ָ����������ʼ��
 *  		  int lastIndexOf(int ch)   ����ָ���ַ��ڴ��ַ��������һ�γ��ִ���������
 *  2.�ж�
 *  	2.1	boolean contains(CharSequence s) ���ҽ������ַ�������ָ���� char ֵ����ʱ������ true�� 
 *  	2.2 boolean isEmpty() ���ҽ��� length() Ϊ 0 ʱ���� true
 *  	2.3 boolean startsWith(String prefix)   ���Դ��ַ����Ƿ���ָ����ǰ׺��ʼ�� 
 *  	2.4 boolean endsWith(String suffix)   ���Դ��ַ����Ƿ���ָ���ĺ�׺������
 *  	2.5 boolean equals(Object anObject)   �����ַ�����ָ���Ķ���Ƚ�
 *  	2.6 boolean equalsIgnoreCase(String anotherString) ���� String ����һ�� String �Ƚϣ������Ǵ�Сд�� 
 *  3.ת��
 *  	3.1 String(char[] value)  ����һ���µ� String��ʹ���ʾ�ַ���������е�ǰ�������ַ����С�
 *  		String(char[] value, int offset, int count) ����һ���µ� String��������ȡ���ַ��������һ����������ַ���
          	static String copyValueOf(char[] data) ����ָ�������б�ʾ���ַ����е� String�� 
 *  	3.2
 *  	3.3
 *  	3.4
 *  
 */
public class String�������� {
	public static void main(String[] args) {
		int[] a ={1,2,3,4};
		String str = "abcdefg abcd";
		System.out.println(str);
		System.out.println(str.length());
		System.out.println(a.length);
		
		//����������ȡ�ַ�
		System.out.println(str.charAt(4));
		
		//�����ַ���ȡ����
		System.out.println(str.indexOf('a'));
		System.out.println(str.indexOf('a',3));
		System.out.println(str.indexOf('m'));//û���ҵ�����-1
		
		//��������һ���ַ�����λ��
		System.out.println(str.lastIndexOf('a'));//��Ȼ�Ƿ������������Ƿ���ֵ�������������λ��
		
		System.out.println(str.startsWith("abc"));
		System.out.println(str.endsWith("cd"));
		System.out.println(str.contains("g "));
		
		if(str.indexOf("aa")== -1)
			System.out.println("����");
		if(str.contains("aa")==false)
			System.out.println("�Ǻ�");
		
		char[] arr = {'a','b','c','d'};
		System.out.println(arr);
		String s = new String(arr);
		System.out.println(s);
		String s1 = new String(arr,1,2);
		System.out.println(s1);
		
		String s2 = "dong";
		char[] arr2 = s2.toCharArray();
		for(int i=0;i<arr2.length;i++)
			System.out.println("arr"+i+" = "+arr[i]);
		
		s2 = "hello java";
		String s3 = s2.replace('a', 'p');
		System.out.println(s3);
		
		s3 = s2.replace("java", "word");
		System.out.println(s3);
		
		
		//�������ַ����и�
		String s4 = "���������ģ�����";
		String[] s5 = s4.split("��");//�и�
		for(int i=0;i<s5.length;i++)
			System.out.println(s5[i]);
		
		String[] ss = new String[3];
		int x = s4.indexOf("��");
		int y = s4.indexOf("��",x);
		int z = s4.indexOf("��",y);
		ss[0] = s4.substring(0,x);
		ss[1] = s4.substring(x,y);
		ss[2] = s4.substring(y,z);
		for(int i=0;i<ss.length;i++)
			System.out.println(s5[i]);
		
		String s6 = "abcdef";
		System.out.println(s6.substring(2));
		System.out.println(s6.substring(2,4));//�ڶ�������  ����ͷ��������β���������ص���   �ӽǱ�  2--3 ���ַ�
		
		String s7 = "   Hello , java    ";
		System.out.println(s7.toLowerCase());//Сд
		System.out.println(s7.toUpperCase());//ת���ɴ�д
		System.out.println(s7.trim());//ȥ�����˿ո�
		
		String s8 = "add";
		String s9 = "aaa";
		String s10 = "a1";// 1 �� ASCII��  49  a �� ASCII�� 97
		String s11 = "ADD";
		System.out.println(s8.compareTo(s9));
		System.out.println(s10.compareTo(s9));// ��1��  -  ��a'  =  -48
		System.out.println(s8.compareToIgnoreCase(s11));//���Դ�Сд�Ƚ�
		char c = 49;
		System.out.println(c);
	}
}
