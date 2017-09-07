package _11;

import java.awt.*;
import java.awt.event.*;

public class Tank {
	private int x,y;// x  y  ������tank���ڵ�λ��
	private static final int WIDTH = 30,HEIGHT = 30;//̹�˴�С
	private static final int XSPEED = 5,YSPEED = 5;//̹��xy�����˶��ٶ�	
	//����Tank��8��������
	private boolean bL = false ,bU = false ,bR = false ,bD = false;//���ڼ�¼  ���̰��µ�  ��������  ������֮�������ΪTrue��
	enum Direction {L, LU, U, RD, R, RU, D, LD, STOP};//������ʾTank�ǳ� �ĸ������ߵ�   �Ժ����ö�پ�������̹�˵�����
	private Direction dir = Direction.STOP;//̹�˵��ʼ�ķ���
	private Direction ptDir = Direction.D;//��Ͳ�ʼ�ķ���
	private TankClient tc = null;
	
	public Tank(int x,int y,TankClient tc){//��ȡTankClient�����ã���Tank���Ե���TankClient��������ݣ���Ϊ�ӵ��ķ�������Tank�����ģ���TankClientҪ��ȡBullets����
		this.x = x;
		this.y = y;
		this.tc = tc;
	}
	
	public void drawTank(Graphics g){
		Color c = g.getColor();//��ȡ��ͼ�������ĵĵ�ǰ��ɫ��
		g.setColor(Color.blue);
		g.fillOval(x, y, WIDTH, HEIGHT);
		g.setColor(c);//����ͼ�������ĵĵ�ǰ��ɫ����Ϊָ����ɫ
		
		ptDraw(g);
		move();
	}
	//�����ж�  tank ���ĸ�������		��ö���������   ���ж������ĸ������ߵ�	 �Ӵ� x y �ĸı�ʹ�move�����������ı䣨ԭ���Ǵ�KeyAdapter ����ı�ģ�
	private void move(){
//		int xBorder = x,yBorder = y;
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
		case STOP : break;
		}
//		if(x<=0 || y<=0 || x>=TankClient.WIDTH-Tank.WIDTH || y>=TankClient.HEIGHT-Tank.WIDTH){
//			x = xBorder;
//			y = yBorder;
//		}
		if(x<=0)
			x = 0;
		if(y<=30)
			y = 30;
		if(x>=TankClient.WIDTH-Tank.WIDTH)
			x = TankClient.WIDTH-Tank.WIDTH;
		if(y>=TankClient.HEIGHT-Tank.WIDTH)
			y=TankClient.HEIGHT-Tank.WIDTH;
	}
	//������Ͳ
	private void ptDraw(Graphics g){
		switch(ptDir){
		case L : 
			g.drawLine(x+Tank.WIDTH/2, y+Tank.HEIGHT/2, x, y+Tank.HEIGHT/2); break;
		case LU :
			g.drawLine(x+Tank.WIDTH/2, y+Tank.HEIGHT/2, x, y); break;
		case U :
			g.drawLine(x+Tank.WIDTH/2, y+Tank.HEIGHT/2, x+Tank.HEIGHT/2, y); break;
		case RD :
			g.drawLine(x+Tank.WIDTH/2, y+Tank.HEIGHT/2, x+Tank.HEIGHT, y+Tank.HEIGHT); break;
		case R :
			g.drawLine(x+Tank.WIDTH/2, y+Tank.HEIGHT/2, x+Tank.HEIGHT, y+Tank.HEIGHT/2); break;
		case RU :
			g.drawLine(x+Tank.WIDTH/2, y+Tank.HEIGHT/2, x+Tank.HEIGHT, y); break;
		case D :
			g.drawLine(x+Tank.WIDTH/2, y+Tank.HEIGHT/2, x+Tank.HEIGHT/2, y+Tank.HEIGHT); break;
		case LD :
			g.drawLine(x+Tank.WIDTH/2, y+Tank.HEIGHT/2, x, y+Tank.HEIGHT); break;
		}
	}
	
	private void realDirection(){//Tank�����ߵķ���  L, LU, U, RD, R, RU, D, LD, STOP   ȡ����dir��ֵ
		if(bL && !bU && !bR && !bD)
			dir = Direction.L;
		else if(bL && bU && !bR && !bD)
			dir = Direction.LU;
		else if(!bL && bU && !bR && !bD)
			dir = Direction.U;
		else if(!bL && !bU && bR && bD)
			dir = Direction.RD;
		else if(!bL && !bU && bR && !bD)
			dir = Direction.R;
		else if(!bL && bU && bR && !bD)
			dir = Direction.RU;
		else if(!bL && !bU && !bR && bD)
			dir = Direction.D;
		else if(bL && !bU && !bR && bD)
			dir = Direction.LD;
		else if(!bL && !bU && !bR && !bD)
			dir = Direction.STOP;
		
		if(dir != Direction.STOP)
			ptDir = dir;
	}
	
	private Bullets fire(){//Tank�����ӵ�   ���ӵ�һ���źţ������ӵ����Լ�ָ���ķ����ӵ�
		int x = this.x + Tank.WIDTH/2 - Bullets.WIDTH/2;
		int y = this.y + Tank.HEIGHT/2 - Bullets.HEIGHT/2;
		Bullets b = new Bullets(x,y,ptDir);
		return b;
	}
	
	//��Ӱ����¼�
	class MyKeyEvent extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
			int key = e.getKeyCode();
			switch(key){
			case KeyEvent.VK_UP    : bU = true; break;//ע�����ﲻ����e.VK_UP  e�Ǳ����ˣ����ܳ��ֱ���
			case KeyEvent.VK_DOWN  : bD = true; break;
			case KeyEvent.VK_RIGHT : bR = true; break;
			case KeyEvent.VK_LEFT  : bL = true; break;
			
			case KeyEvent.VK_Q	   : tc.myBullets.add(fire()); break;//����Q���Ϳ��Ի�ȡ�ӵ�  ��λ�ú�  ̹�����ڵķ����ӵ��ķ���Ȼ�����paint�����ػ��ӵ�
			case KeyEvent.VK_SPACE : tc.myBullets.clear();
			}
			realDirection();//����ֻ���ж����Ǽ������������£�������tank�������ǿ�dir��ֵ
		}
		public void keyReleased(KeyEvent e) {
			int key = e.getKeyCode();
			switch(key){
			case KeyEvent.VK_UP    : bU = false; break;//ע�����ﲻ����e.VK_UP  e�Ǳ����ˣ����ܳ��ֱ���
			case KeyEvent.VK_DOWN  : bD = false; break;
			case KeyEvent.VK_RIGHT : bR = false; break;
			case KeyEvent.VK_LEFT  : bL = false; break;
			}
			realDirection();//����ֻ���ж����Ǽ����������ͷ�
		}
	}
}
