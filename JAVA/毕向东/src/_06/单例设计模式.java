package _06;
/**�������ģʽ�����һ�������ڴ���ֻ����һ������
 *
 *��Ҫ��֤����Ψһ��
 *1��Ϊ�˱�������������ഴ�������Ƚ�ֹ�������򴴽��������
 *2��Ϊ��������������ʸ�������������Զ���һ����
 *3��Ϊ�˷�������������Զ��������ʣ����Զ����ṩһЩ���ʷ�ʽ
 *
 *���������
 *1�����캯������˽�л�
 *2���ڱ����д���һ������Ķ���
 *3���ṩһ�����������Ի�ȡ���������
 */
//������ȳ�ʼ�����󣬳�Ϊ������ʽ
class Signal{
	
	private Signal(){}
	
	private static Signal s = new Signal();
	
	public static Signal getSignal(){//����һ������ֵΪSignal�ķ���
		return s;
	}
	
	//������룬��������֤ ���Ƿ����ڴ�ֻ�ܴ���һ������
	private int age;

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}
}
//����ǡ�������������ʱ�ų�ʼ����Ҳ�����������ʱ���أ���Ϊ������ʽ
class Signal2{

	private Signal2(){}

	private static Signal2 s = null;
	
	public static Signal2 getSignal2(){
		if(s == null)
			s = new Signal2();
		return s;
	}
}
public class �������ģʽ {
	public static void main(String[] args) {
		
		Signal s = Signal.getSignal();
		System.out.println("age = "+s.getAge());
		
		s.setAge(20);//�ı���У���Sighal�࣬�����е�	age ��ֵ
		
		Signal s2 = Signal.getSignal();
		System.out.println("age = "+s2.getAge());//�������ͬһ�����󣬣���ô   s2.getAge  Ӧ�ú����� s.getAge ��ֵһ��
	}
}
