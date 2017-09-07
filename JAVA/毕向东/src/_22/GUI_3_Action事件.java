package _22;

import java.awt.*;
import java.awt.event.*;

public class GUI_3_Action�¼� {
	private Frame f;
	private Button but;
	GUI_3_Action�¼�(){
		init();
	}
	
	public void init(){
		f = new Frame("My Frame");
		
		//��Frame���мƱ�����
		f.setBounds(300,100,600,500);
		
		f.setLayout(new FlowLayout());
		but = new Button("my button");
		
		//�������ӵ�Frame��
		f.add(but);
		
		//���ش����¼�
		myEvent();
		
		//��ʾ
		f.setVisible(true);
	}
	
	private void myEvent(){
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.out.println("�˳�");
				System.exit(0);
			}
		});
		//�ð�ť�߱����������
		/*���ģ�Component->Button(����)->addActionListener(ActionListener l)��������->ActionListener��������
		 */
		but.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				System.out.println("��ť����");
			}
		});
	}
	
	public static void main(String[] args) {
		new GUI_3_Action�¼�();
	}
}
