package _22;

import java.awt.*;
import java.awt.event.*;
/*
 * �¼����������ص㣺
 * 1���¼�Դ
 * 2���¼�
 * 3��������
 * 4���¼�����
 * 
 * �¼�Դ������awt������swing���е���Щͼ�ν������
 * 
 * �¼���ÿһ���¼�Դ�����Լ����еĶ�Ӧ�¼��͹����¼�
 * 
 * �����������Դ���ĳһ���¼��Ķ������Ѿ���װ���˼�������
 * 
 * �������ߣ�java���������
 * 
 * ����Ҫ���ľ��ǣ��Բ����Ķ������д���
 */
//��ΪwindowListener������WindowAdapter�Ѿ�ʵ����WindowListener�ӿ�
//��������֮�����еķ�������ô��ֻҪ�̳�WindowAdapter��������Ҫ�ķ�������
class MyWin extends WindowAdapter{
	public void windowClosing(WindowEvent e){
//		System.out.println("window closing---"+e.toString());
		System.exit(0);
	}
}
public class GUI_2_�¼��������� {
	public static void main(String[] args) {
		Frame f = new Frame("hello world");
		f.setLocation(400,200);
		f.setSize(500,400);
		f.setLayout(new FlowLayout());//������ʽ����
		
		Button b = new Button("����һ����ť");//Ĭ�ϱ߽�ʽ���
		f.add(b);

		//void addWindowStateListener(WindowStateListener l) ���ָ���Ĵ���״̬���������ԴӴ˴��ڽ��մ����¼��� 
		f.addWindowListener(new WindowAdapter(){//Adapt����������д������˼
			public void windowClosing(WindowEvent e){//�ر�ʱ����
		          
				System.out.println("�ر�");
				System.exit(0);
			}
			public void windowActivated(WindowEvent e){// �����ʱ���� ��ÿ������ǰ�ã��ͻᴥ����
				System.out.println("active");
			}
			public void windowOpened(WindowEvent e){//�Ѵ򿪴���ʱ����
				System.out.println("����");
			}
			 
		});
		
		f.setVisible(true);
	}
}
