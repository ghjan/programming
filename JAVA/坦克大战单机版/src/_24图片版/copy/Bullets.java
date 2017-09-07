package _24ͼƬ��.copy;

import java.awt.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Bullets {//�ӵ���
	private int x,y;//̹�˵�λ�ã�Ҳ���ӵ���λ��
	private boolean live = true;
	public static final int WIDTH = 10, HEIGHT = 10;//�ӵ���С
	private static final int XSPEED = 10,YSPEED = 10;//�ӵ��ٶ�
	private TankClient tc;
	private boolean good;//���ڱ�ʶ�ӵ�����һ�����ӵ�
	Direction dir;
	
	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Map<String,Image> imags = new HashMap<String,Image>();
	private static Image[] tankImage = null;
	static {
		tankImage = new Image[]{//L, LU, U, RD, R, RU, D, LD, STOP
				tk.getImage(Explode.class.getClassLoader().getResource("images/missileL.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/missileLU.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/missileU.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/missileRD.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/missileR.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/missileRU.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/missileD.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/missileLD.gif"))
		};
		imags.put("L", tankImage[0]);
		imags.put("LU", tankImage[1]);
		imags.put("U", tankImage[2]);
		imags.put("RD", tankImage[3]);
		imags.put("R", tankImage[4]);
		imags.put("RU", tankImage[5]);
		imags.put("D", tankImage[6]);
		imags.put("LD", tankImage[7]);
	}

	public Bullets(int x,int y,Direction dir,boolean good,TankClient tc){
		this.x = x;
		this.y = y;
		this.dir = dir;
		this.good = good;
		this.tc = tc;
	}
	
	public void draw(Graphics g){
		if(!live){
			tc.myBullets.remove(this);//����ɾ���ӵ�����Ȼ��һ���ӵ����е��ˣ���һ��������������ط�Ҳ����
			return;
		}
		if(good){
			Color c = g.getColor();
			g.setColor(Color.black);
			g.fillOval(	x, y, WIDTH, HEIGHT);
			g.setColor(c);
		}
		
			switch(dir){
			case L : 
				g.drawImage(imags.get("L"),x, y, null); break;
			case LU :
				g.drawImage(imags.get("LU"),x, y, null); break;
			case U :
				g.drawImage(imags.get("U"),x, y, null); break;
			case RD :
				g.drawImage(imags.get("RD"),x, y, null); break;
			case R :
				g.drawImage(imags.get("R"),x, y, null); break;
			case RU :
				g.drawImage(imags.get("RU"),x, y, null); break;
			case D :
				g.drawImage(imags.get("D"),x, y, null); break;
			case LD :
				g.drawImage(imags.get("LD"),x, y, null); break;
			case STOP :
				g.drawImage(imags.get("STOP"),x, y, null); break;
			}
		
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
