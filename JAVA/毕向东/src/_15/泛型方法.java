package _15;
/*
 * �����ඨ��ķ��ͣ�������������Ч�����������ʹ�ã�
 * ��ô������Ķ�����ȷҪ�����ľ������ͺ�����Ҫ���������;��Ѿ��̶���
 * 
 * Ϊ���ò�ͬ�������Բ�����ͬ���ͣ��������ͻ���ȷ��
 * ��ô���Խ����Ͷ����ڷ�����
 * 
 * ���⣺
 * ��̬���������Է������϶���ķ���
 * �����̬���������������������Ͳ�ȥ�������Խ����Ͷ����ڷ�����
 */
class Demo{
	public <T> void show(T t){
		System.out.println(t);
	}
	//��������Ҳ�����У����ͷ���
	public <Q> void print(Q q){
		System.out.println(q);
	}
	
	public static <W> void method(W w){
		System.out.println(w);
	}
	
}
public class ���ͷ��� {

	public static void main(String[] args) {
		Demo d = new Demo();
		d.show("haha");
		d.show(123);
		d.show(new Integer(123));
		
		d.print("dong");
		d.print(123);
		
		d.method("hahahahahaha");
		
	}

}
