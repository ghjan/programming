package _5;

import java.awt.*;
import java.awt.event.*;

public class Tank {
	private int x,y;

	public Tank(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public void drawTank(Graphics g){
		Color c = g.getColor();//��ȡ��ͼ�������ĵĵ�ǰ��ɫ��
		g.setColor(Color.blue);
		g.fillOval(x, y, 30, 30);
		
		g.setColor(c);//����ͼ�������ĵĵ�ǰ��ɫ����Ϊָ����ɫ
	}
	
	public static void main(String[] args) {
		
	}
	//��Ӱ����¼�
	class KeyPressed extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
			int key = e.getKeyCode();
			switch(key){
			case KeyEvent.VK_UP    : y-=5;break;//ע�����ﲻ����e.VK_UP  e�Ǳ����ˣ����ܳ��ֱ���
			case KeyEvent.VK_DOWN  : y+=5;break;
			case KeyEvent.VK_RIGHT : x+=5;break;
			case KeyEvent.VK_LEFT  : x-=5;break;
			}
		}
	}
}
