package _2;

import java.awt.*;
import java.awt.event.*;
/*
 *  void setResizable(boolean resizable) 
          ���ô˴����Ƿ�����û�������С�� 
    
    public abstract Color getColor()��ȡ��ͼ�������ĵĵ�ǰ��ɫ��
    
    public abstract void setColor(Color c)����ͼ�������ĵĵ�ǰ��ɫ����Ϊָ����ɫ��ʹ�ô�ͼ�������ĵ����к���ͼ�β�����ʹ�����ָ������ɫ�� 
 */
public class TankClient extends Frame{
	public void paint(Graphics g) {
		Color c = g.getColor();//��ȡ��ͼ�������ĵĵ�ǰ��ɫ��
		g.setColor(Color.blue);
		g.fillOval(50, 50, 30, 30);
		
		g.setColor(c);//����ͼ�������ĵĵ�ǰ��ɫ����Ϊָ����ɫ
	}

	public void lauchFrame(){
		this.setBounds(250,100,800,600);
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		this.setResizable(false);//���ò����Ե�����С
		this.setBackground(Color.black);
		
		
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new TankClient().lauchFrame();
	}
}
