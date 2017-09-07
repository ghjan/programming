package _09;
/*��Ŀ��
 * ����ʦ�õ����Ͽ�
 * 
 * prelect����
 * restart����
 */
class BlueScreenException extends Exception{//�����Գ����������쳣ʱ����ʦ�ܴ���
	BlueScreenException(String message){
		super(message);
	}
}
class ComputerSmokeException extends Exception{//������ð�̣��쳣ʱ����ʦ���ܴ���
	ComputerSmokeException(String message){
			super(message);
		}
}
class NoPlanException extends Exception{		//��ʦ���ܴ���ʱ���׳�ȥ���쳣
	NoPlanException(String message){
		super(message);
	}
}
class Computer{
	public int state = 3;//1��������												����  ����  1 2 3  ����Ч��
	public void run()throws BlueScreenException,ComputerSmokeException{
		if(state == 2)
			throw new BlueScreenException("����������");
		if(state == 3)
			throw new ComputerSmokeException("����ð����");//�ѵ���ð���׳�ȥ
		
		System.out.println("��������");
	}
	
	public void restart() throws BlueScreenException, ComputerSmokeException{//��Ϊ��������run();���������Ա������throws(�������쳣���׳��쳣)
		System.out.println("��������");
		state = 1;//��ʾ����������
		run();
	}
}
class Teacher{
	private String name;
	private Computer c;
	Teacher(String name,Computer c){//Ϊ�˷��㣬���ǳ��˴���ʦ�����֣������������ڵ������ڵ�״̬
		this.name = name;
		this.c = c;
	}
	
	public void prelect()throws NoPlanException, BlueScreenException, ComputerSmokeException{//��ʦ�޷�������׸�   ���ࡢ�������ڵ�����restart
		try {																	//restart����run();���Եü���BlueScreenException, ComputerSmokeException
			c.run();				//��������ʱ���ܻ����
		} catch (BlueScreenException e) {
			System.out.println(e.getMessage());
			System.out.println(name+"˵��С��˼�������");
			c.restart();					//��������ʦ���Դ���������
		}catch (ComputerSmokeException e) {
			throw new NoPlanException("��ʱ�޷�����,��Ϊ��"+e.getMessage());//��ʦ�޷���������Ҫ�׳�����ʱ�޷�����,��Ϊ������ð���ˣ�
		}												//e.getMessage()��ȡ��ʱ�޷�������ԭ�򣺵���ð����
		
		System.out.println("��ʦ��ʼ����");
	}
}

public class �쳣��ϰ {
	public static void main(String[] args) throws BlueScreenException, ComputerSmokeException{//t.prelect�в�ֹNoPlanException��һ���쳣
		Computer c = new Computer();//����BlueScreenException, ComputerSmokeException�������쳣��У��ѡ���׳���У���������ԣ���У��ֻ����NoPlanException�쳣
		
		for(int i=1;i<4;i++){
			System.out.println("The state of the Computer is :"+i);
			c.state = i;
			Teacher t = new Teacher("����ʦ",c);
			try {
				t.prelect();
			} catch (NoPlanException e) {
				System.out.println("��ʦ˵��"+e.getMessage());
				System.out.println("У��������ʦ��ż�");//�������Ǽ���   У������ʦ�ż�  ��  ����ʦ
			}
		}

	}
}
