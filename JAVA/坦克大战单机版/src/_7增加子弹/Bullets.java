package _7�����ӵ�;

import java.awt.*;

public class Bullets {//�ӵ���
	private int x,y;
	private static final int XSPEED = 10,YSPEED = 10;
	
	Tank.Direction dir;
	
	
	
	public Bullets(int x, int y, Tank.Direction dir) {
		this.x = x;
		this.y = y;
		this.dir = dir;
	}
	
	public void drawBullets(Graphics g){
		Color c = g.getColor();
		g.setColor(Color.black);
		g.fillOval(	x, y, 10, 10);
		g.setColor(c);
		
		move();
	}
	
	//�ӵ��Լ����ƶ������ٶ�
	private void move() {
		switch(dir){
		case L : 
			x-=XSPEED; break;
		case LU :
			x-=XSPEED; y-=YSPEED; break;
		case U :
			y-=XSPEED; break;
		case RD :
			x+=XSPEED; y+=YSPEED; break;
		case R :
			x+=XSPEED; break;
		case RU :
			x+=XSPEED; y-=YSPEED; break;
		case D :
			y+=YSPEED; break;
		case LD :
			x-=XSPEED; y+=YSPEED; break;
		}
	}
	
	
}
