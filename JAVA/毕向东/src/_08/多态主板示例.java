package _08;
/*
 * PCI��Peripheral Component Interconnect(���貿��������׼)����д������Ŀǰ���˵�����ʹ����Ϊ�㷺�Ľӿڣ��������е������Ʒ�϶��������ֲ��
 * 
 * ԭ��PCI p1 = new NetCard()   ����Ҳ������̬��������ӿھ��൱���˸���
 */
interface PCI{
	public void open();
	public void close();
}

class MainBoard{
	public void run(){
		System.out.println("MainBoard run");
	}
	
	public void usePCI(PCI p){//����������һ���ӿ�****�κ�һ����չ�����PCI�ӿڵ��඼���Դ�����*****{ԭ����̬�����������ֵ�PCI p1 = new NetCard()}
		if(p != null){
			p.open();//����PCI�ӿڣ���������ʵ�ֵķ���
			p.close();
		}
	}
}

class NetCard implements PCI{//PCI  ��չ��  ����
	public void open(){								//ʵ�ֽӿ��еĸ������ķ���
		System.out.println("NetCard open");
	}
	public void close(){
		System.out.println("NetCard close");
	}
	public void show(){
		System.out.println("��������");
	}
}
class SoundCard implements PCI{//PCI  ��չ������
	public void open(){
		System.out.println("SoundCard open");
	}
	public void close(){
		System.out.println("SoundCard close");
	}
	public void show(){
		System.out.println("��������");
	}
}

public class ��̬����ʾ�� {
	public static void main(String[] args) {
		MainBoard m = new MainBoard();
		m.run();
		m.usePCI(null);//��ʾĿǰΪֹ����û���κ�PCI�豸
		m.usePCI(new NetCard());
		m.usePCI(new SoundCard());
		
		//�������Լ�����չ
		System.out.println();
		PCI p1 = new NetCard();
		PCI p2 = new SoundCard();
		p1.open();
		p2.open();
		p1.close();
		p2.close();
		//p1.show();  ���Ǵ���� ����  �ӿ���û��  show �������
		new NetCard().show();
		new SoundCard().show();
	}
}
