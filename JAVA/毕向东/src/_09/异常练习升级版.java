package _09;
/*��Ŀ��
 * ����ʦ�õ����Ͽ�
 * 
 * prelect����
 * restart����
 */
class Teacher1{
	private String name;
	private Computer c;
	Teacher1(String name,Computer c){
		this.name = name;
		this.c = c;
	}
	
	public void prelect()throws BlueScreenException, ComputerSmokeException{//��ʦ�޷�������׸�   ���ࡢ�������ڵ�����restart
		try {																	//restart����run();���Եü���BlueScreenException, ComputerSmokeException
			c.run();				//��������ʱ���ܻ����
		} catch (BlueScreenException e) {
			throw new BlueScreenException("��ʱ�޷�����,��Ϊ��"+e.getMessage());
		}catch (ComputerSmokeException e) {
			throw new ComputerSmokeException("��ʱ�޷�����,��Ϊ��"+e.getMessage());//��ʦ�޷���������Ҫ�׳�����ʱ�޷�����,��Ϊ������ð���ˣ�
		}												
		System.out.println("��ʦ��ʼ����");
	}
	
}

public class �쳣��ϰ������ {
	public static void main(String[] args) throws BlueScreenException, ComputerSmokeException{
		Computer c = new Computer();
		
		for(int i=1;i<4;i++){
			System.out.println("The state of the Computer is :"+i);
			c.state = i;
			Teacher1 t = new Teacher1("����ʦ",c);
			try {
					t.prelect();
				}catch (ComputerSmokeException e) {
				System.out.println("��ʦ˵��"+e.getMessage());
				System.out.println("У��������ʦ��ż�");//�������Ǽ���   У������ʦ�ż�  ��  ����ʦ
			}catch (BlueScreenException e){
				System.out.println("��ʦ˵��"+e.getMessage());
				System.out.println("У��˵����������������");
				c.restart();
				System.out.println("��ʦ��ʼ����");
			}
		}

	}
}
