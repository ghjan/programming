package _21Ѫ��ͼ�λ�;

import java.awt.*;
import java.util.List;

public class Bullets {//�ӵ���
	private int x,y;//̹�˵�λ�ã�Ҳ���ӵ���λ��
	private boolean live = true;
	public static final int WIDTH = 10, HEIGHT = 10;//�ӵ���С
	private static final int XSPEED = 10,YSPEED = 10;//�ӵ��ٶ�
	private TankClient tc;
	private boolean good;//���ڱ�ʶ�ӵ�����һ�����ӵ�
	Tank.Direction dir;
	
	public Bullets(int x,int y,Tank.Direction dir,boolean good,TankClient tc){
		this.x = x;
		this.y = y;
		this.dir = dir;
		this.good = good;
		this.tc = tc;
	}
	
	public void drawBullets(Graphics g){
		if(!live){
			tc.myBullets.remove(this);//����ɾ���ӵ�����Ȼ��һ���ӵ����е��ˣ���һ��������������ط�Ҳ����
			return;
		}
		Color c = g.getColor();
		if(!good)
			g.setColor(Color.black);
		else
			g.setColor(Color.green);
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
		if(x<0 || y<0 || x>TankClient.WIDTH || y>TankClient.HEIGHT){//�ӵ������߽�  ���������ӵ�������ɾ��
			live = false;
		}
	}
	
	public Rectangle getRect(){
		return new Rectangle(x,y,WIDTH,HEIGHT);
	}
	
	
	//��������ж�  ̹���Ƿ񱻻��У�һ�����к�ᷢ�����£�һ���������Խ������һ�������������ѭ�������԰������ڵڶ��������ֻ�ǲ����׿����ѣ�
	public void hitTanks(List<Tank> tanks){
		for(int i=0;i<tanks.size();i++)
			hitTank(tanks.get(i));//ÿ�Σ������������ж�ÿһ��̹���Ƿ񱻻���
	}
	public void hitTank(Tank t){
		//�ж��Ƿ�����̹�˵�������Ƿ���ӵ�������������̹�˱�����ţ���Ȼ�����Ժ��ӵ�����ͬλ�ã��ӵ�Ҳ����ʧ
		if(this.getRect().intersects(t.getRect()) && t.isLive() && this.good != t.isGood()){//boolean intersects(Rectangle r) ȷ���� Rectangle �Ƿ���ָ���� Rectangle �ཻ�� 
			if(t.isGood()){
				t.setLife(t.getLife()-20);//ÿ�����Ǳ����оͼ���20��Ѫ
				if(t.getLife()<=0)
					t.setLive(false);
			} else//����ǵз�̹�˾�ֱ����
			t.setLive(false);//������ҲŪ���������ѱ�־live����Ϊfalse������
			
			this.live = false;//���ӵ�ҲŪ��ʧ
			Explode e = new Explode(x,y,tc);//ÿ�λ���������һ����ը��
			tc.explodes.add(e);//��TankClient�ı�ը���ϣ�����һ����ը
		}
	}
	
	public void hitWall(Wall w){//�ж��Ƿ�ײ��ǽ��
		if(this.live && this.getRect().intersects(w.getRect())){
			this.live = false;
		}
	}
	
}
