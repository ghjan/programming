package _05;

public class �������� {
	public static void main(String[] args) {
		Car c = new Car();
		c.run();

		new Car().run();//����ͽ���  ��������
		
		// �������ַ���������� ������Ч��һ��
		new Car().color = "a";//��������

		show(c);//��c ���뷽�����档�ڷ�������ı����ɫ��Ҳ��c �ı����ɫ
		c.run();//��ɫҲ����� ��ɫ
		
		show(new Car());//������Ҳ���ԣ������ˣ��������������Ϊʵ��ʹ�ã�
	}
	
	public static void show(Car c){
		c.color = "��ɫ";
		c.run();
	}
}
/*������ķ���ֻ����һ��ʱ������ʹ����������
 *����һ������Ķ����Ա����ʱ������������������
 * */
