package _13;
/*
 * JDK1.5�汾���������
 * 
 */
public class �����������Ͷ����װ�������� {
	public static void main(String[] args) {
//		Integer x = new Integer("123");
//		Integer y = new Integer("123");
//		
//		System.out.println(x==y);//ָ��ġ�����ͬ
//		System.out.println(x.equals(y));
		
		Integer x = 4;//�Զ�װ�䣨new Integer(4)��
		x = x + 2;//x+2��x�������Զ����䣬�����int���ͣ���2���мӷ����㣬�ٽ����Զ�װ�丳��x
		
		Integer m = 128;
		Integer n = 128;
		System.out.println(m==n);
		Integer a = 127;
		Integer b = 127;
		System.out.println(a==b);//���Ϊtrue����Ϊa��bָ����ͬһ��Integer
									//��Ϊ����ֵ��byte��Χ��ʱ�����������ԣ��������ֵ�Ѿ����ڣ��򲻻��ٿ����¿ռ�
		
	}
}
