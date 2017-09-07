package _15;

import java.awt.*;
import java.util.List;

public class Bullets {//�ӵ���
	private int x,y;//̹�˵�λ�ã�Ҳ���ӵ���λ��
	private boolean live = true;
	public static final int WIDTH = 10, HEIGHT = 10;//�ӵ���С
	private static final int XSPEED = 10,YSPEED = 10;//�ӵ��ٶ�
	private TankClient tc;
	Tank.Direction dir;
	
	public Bullets(int x, int y, Tank.Direction dir) {
		this.x = x;
		this.y = y;
		this.dir = dir;
	}
	public Bullets(int x,int y,Tank.Direction dir,TankClient tc){
		this(x, y, dir);
		this.tc = tc;
	}
	
	public void drawBullets(Graphics g){
		if(!live) return;
		Color c = g.getColor();
		g.setColor(Color.black);
		g.fillOval(	x, y, WIDTH, HEIGHT);
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
//		if(x<0 || y<0 || x>TankClient.WIDTH || y>TankClient.HEIGHT){
//			live = false;
//		}
	}
	
	public Rectangle getRect(){
		return new Rectangle(x,y,WIDTH,HEIGHT);
	}
	
	
	//��������ж�  ̹���Ƿ񱻻��У�һ�����к�ᷢ�����£�һ���������Խ������һ�������������ѭ�������԰������ڵڶ��������ֻ�ǲ����׿����ѣ�
	public void hitTanks(List<Tank> tanks){
		for(int i=0;i<tanks.size();i++)
			hitTank(tanks.get(i));//ÿ�Σ������������ж�ÿһ��̹���Ƿ񱻻���
	}
	public boolean hitTank(Tank t){					//̹�˱�����ţ���Ȼ�����Ժ��ӵ�����ͬλ�ã��ӵ�Ҳ����ʧ
		if(this.getRect().intersects(t.getRect()) && t.isLive()){//boolean intersects(Rectangle r) ȷ���� Rectangle �Ƿ���ָ���� Rectangle �ཻ�� 
			t.setLive(false);//������ҲŪ���������ѱ�־live����Ϊfalse������
			this.live = false;//���ӵ�ҲŪ��ʧ
			Explode e = new Explode(x,y,tc);//ÿ�λ���������һ����ը��
			tc.explodes.add(e);//��TankClient�ı�ը���ϣ�����һ����ը
			return true;
		}
		return false;
	}
	
}
