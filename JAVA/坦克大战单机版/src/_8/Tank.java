package _8;

import java.awt.*;
import java.awt.event.*;

public class Tank {
	private int x,y;// x  y  ������tank���ڵ�λ��
	private static final int WIDTH = 30,HEIGHT = 30;//̹�˴�С
	private static final int XSPEED = 5,YSPEED = 5;//̹��xy�����˶��ٶ�	
	//����Tank��8��������
	private boolean bL = false ,bU = false ,bR = false ,bD = false;//���ڼ�¼  ���̰��µ�  ��������  ������֮�������ΪTrue��
	enum Direction {L, LU, U, RD, R, RU, D, LD, STOP};//������ʾTank�ǳ� �ĸ������ߵ�   �Ժ����ö�پ�������̹�˵�����
	private Direction dir = Direction.STOP;//�ʼ����Ϊֹͣ״̬
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
		
		move();
	}
	//�����ж�  tank ���ĸ�������		��ö���������   ���ж������ĸ������ߵ�	 �Ӵ� x y �ĸı�ʹ�move�����������ı䣨ԭ���Ǵ�KeyAdapter ����ı�ģ�
	private void move(){
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
	}
	
	private Bullets fire(){//Tank�����ӵ�   ���ӵ�һ���źţ������ӵ����Լ�ָ���ķ����ӵ�
		int x = this.x + Tank.WIDTH/2 - Bullets.WIDTH/2;
		int y = this.y + Tank.HEIGHT/2 - Bullets.HEIGHT/2;
		Bullets b = new Bullets(x,y,dir);
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
			
			case KeyEvent.VK_Q	   : tc.myBullets = fire(); break;//����Q���Ϳ��Ի�ȡ�ӵ�  ��λ�ú�  ̹�����ڵķ����ӵ��ķ���
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
