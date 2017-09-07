package _18�Լ����ӵĹ���_����_����_���ӵ���̹��;

import java.awt.*;
import java.util.List;

public class Bullets {//�ӵ���
	private int x,y;//̹�˵�λ�ã�Ҳ���ӵ���λ��
	private boolean live = true;
	public static final int WIDTH = 10, HEIGHT = 10;//�ӵ���С
	private static final int XSPEED = 10,YSPEED = 10;//�ӵ��ٶ�
	private TankClient tc;
	private boolean good;//���ڱ�ʶ�ӵ�����һ�����ӵ�
	private Tank.Direction dir;
	private int superBullets = 0;
	
	public Bullets(int x,int y,Tank.Direction dir,boolean good,TankClient tc){
		this.x = x;
		this.y = y;
		this.dir = dir;
		this.good = good;
		this.tc = tc;
	}
	public Bullets(int x,int y,Tank.Direction dir,boolean good,TankClient tc,int superBullets){
		this(x,y,dir,good,tc);
		this.superBullets = superBullets;
	}
	
	
	public void draw(Graphics g){
		if(!live){
			tc.myBullets.remove(this);//����ɾ���ӵ�����Ȼ��һ���ӵ����е��ˣ���һ��������������ط�Ҳ����
			tc.myBullets_1.remove(this);
			return;
		}
		Color c = g.getColor();
		if(!good){
			g.setColor(Color.black);
			g.fillOval(	x, y, WIDTH, HEIGHT);
		}
		else if(superBullets == 0){
			g.setColor(Color.green);
			g.fillOval(	x, y, WIDTH, HEIGHT);
		}
		else if(superBullets == 1){
			g.setColor(Color.red);
			g.fillRect(x, y, WIDTH, HEIGHT);
		}
		
		
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
