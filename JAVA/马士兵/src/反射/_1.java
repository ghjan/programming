package ����;
import java.lang.reflect.*;

public class _1 {
	public static void main1(String[] args) throws Exception{
		Class c = Class.forName("����.Person");
		Method[] me = c.getMethods();
		for(Method m : me){
			if(m.getName().equals("d2")){
				Class returnType = m.getReturnType();//��ȡ����ֵ
				System.out.println("d1����ֵ"+returnType.getName());
			}
			if(m.getName().equals("d1")){//�жϷ����Ƿ���Ϊd1
				for(Class paramType : m.getParameterTypes())//��ȡ��������
					System.out.println("d1������"+paramType.getName());
				//�����������
				Object o = c.newInstance();//�����˿ղι������
				m.invoke(o, 12,"dong");
			}
		}
	}
	public static void main2(String[] args) throws Exception {
		Class c = Class.forName("����.Person");
		//�����ǹ��еĹ��캯��
		Constructor cs = c.getConstructor(int.class);//�������вεĹ������
		Person d = (Person)cs.newInstance(9);//��ȡ����Ҳ�������ʵ����
		d.d2();//������ķ���
		
		//������˽�й��캯��
		cs = c.getDeclaredConstructor(String.class);
		cs.setAccessible(true);//ֵΪ true ��ָʾ����Ķ�����ʹ��ʱӦ��ȡ�� Java ���Է��ʼ��
		Person p = (Person) cs.newInstance("hello dong");
		p.d1(11002, "dong");
	}
	public static void main3(String[] args) throws Exception {
		//������÷����鷽��
		Class c = Class.forName("����.Person");
		Method[] me = c.getMethods();//��ȡ���з���
		for(Method m : me){
			System.out.println(m.getName());
		}
		
		Method method = c.getMethod("d1", int.class,String.class);//��ȡ����  d1
		Object o = c.newInstance();
		method.invoke(o,1234,"hello");
		
		//�������鷽��  ��main����
		Method main = c.getMethod("main", String[].class);
//		main.invoke(o, new String[]{"aa","bb","cc"});//���������У�JDK����ַ�������ֿ���Ϊ3����������main����ֻ��һ������
		main.invoke(o, (Object)new String[]{"aa","bb","cc"});//��ǿ������ת��  ��ƭjava ʹjava��������ļ����ַ����ֿ�������һ������ 
		main.invoke(o, new Object[]{new String[]{"aa","bb","cc"}});//�����Ͳ�������ƭ�ˣ�ʵʵ���ڵĴ�һ���ַ��������ȥ
	}
	public static void main(String[] args) throws Exception {
		Class c = Class.forName("����.Person");
		Object obj = c.newInstance();
		Field f = c.getField("i");
		//��ȡ�����ֶ�
		Object o = f.get(obj);
		//��ȡ�ֶ�����
		Class type = f.getType();
		if(type.equals(int.class)){
			int i = (int)o;
			System.out.println("i = "+i);
		}
		
		//��ȡ˽��  �ֶ�
		Field f2 = c.getDeclaredField("s");
		f2.setAccessible(true);
		System.out.println("i = "+f.get(obj));
	}
}
