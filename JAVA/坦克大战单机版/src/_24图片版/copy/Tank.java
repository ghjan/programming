package _24ͼƬ��.copy;

import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Tank {
	private int x,y;// x  y  ������tank���ڵ�λ��
	private int oldX,oldY;//��¼̹����һ����λ��
//	private static final int WIDTH = 30,HEIGHT = 30;//̹�˴�С
	private static final int WIDTH = 50,HEIGHT = 50;//̹�˴�С
	private static final int XSPEED = 5,YSPEED = 5;//̹��xy�����˶��ٶ�	
	public int GAME_LEVEL = 14;//Ĭ����Ϸ�Ѷ�Ϊ12  Խ��Խ�򵥣����17  ���3
	//����Tank��8��������
	private boolean bL = false ,bU = false ,bR = false ,bD = false;//���ڼ�¼  ���̰��µ�  ��������  ������֮�������ΪTrue��
	private Direction dir = Direction.STOP;//̹�˵��ʼ�ķ���
	private Direction ptDir = Direction.D;//��Ͳ�ʼ�ķ���
	private TankClient tc = null;
	private boolean good ;
	private boolean live = true;
	private static Random rand = new Random();
	private int step = rand.nextInt(15)+3;//���������һ�������ƶ��Ĳ�������Ȼ������ͬһ���ط��Ҷ�
	private int life = 100;//���ҷ�̹������Ѫ��
	private BloodBar bb  = new BloodBar();
	
	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Map<String,Image> imags = new HashMap<String,Image>();
	private static Image[] tankImage = null;
	static {
		tankImage = new Image[]{
				tk.getImage(Explode.class.getClassLoader().getResource("images/tankL.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/tankLU.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/tankU.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/tankRD.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/tankR.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/tankRU.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/tankD.gif")),
				tk.getImage(Explode.class.getClassLoader().getResource("images/tankLD.gif"))
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
	
	public int getLife() {
		return life;
	}
	public void setLife(int life) {
		this.life = life;
	}
	public void setGood(boolean good) {
		this.good = good;
	}
	public boolean isGood() {
		return good;
	}
	public boolean isLive() {
		return live;
	}
	public void setLive(boolean live) {
		this.live = live;
	}

	public Tank(int x,int y,boolean good,Direction dir,TankClient tc){//��ȡTankClient�����ã���Tank���Ե���TankClient��������ݣ���Ϊ�ӵ��ķ�������Tank�����ģ���TankClientҪ��ȡBullets����
		this.x = x;
		this.y = y;
		this.good = good;
		this.dir = dir;
		this.tc = tc;
	}
	
	public void drawTank(Graphics g){//̹���Լ����Լ�
		if(!live){
			tc.enemyTank.remove(this);
			return;
		}
		
		if(good){
			bb.draw(g);
		}
		
		ptDraw(g);//����Ͳ
		
		move();
	}
	//�����ж�  tank ���ĸ�������		��ö���������   ���ж������ĸ������ߵ�	 �Ӵ� x y �ĸı�ʹ�move�����������ı䣨ԭ���Ǵ�KeyAdapter ����ı�ģ�
	private void move(){
		oldX = x;//��¼��һ����λ��
		oldY = y;
		
		switch(dir){//dir��������̹�˵ķ���
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
		
		if(x<=5)
			x = 5;
		if(y<=30)
			y = 30;
		if(x>=TankClient.WIDTH-Tank.WIDTH-5)
			x = TankClient.WIDTH-Tank.WIDTH-5;
		if(y>=TankClient.HEIGHT-Tank.HEIGHT-5)
			y=TankClient.HEIGHT-Tank.HEIGHT-5;
		
		
		if(this.dir != Direction.STOP)//����ط�̹��   ̹�˷���ΪStop������ô�ı���Ͳ������̹�˷���һ����
			ptDir = dir;
		
		if(!good){//����ǵз�̹��
			if(step == 0){
				Direction[] arr = Direction.values();// ��enumת��Ϊ����
				int r = rand.nextInt(arr.length);//��0��arr����󳤶�
				dir = arr[r];
				step = rand.nextInt(15)+3;//����0---14֮�����
				
				//���з�tank�����ڵ���������̫�ܼ�
				if(step>=GAME_LEVEL) fire();
			}
			step--;
		}
	}
	//������Ͳ
	private void ptDraw(Graphics g){
		switch(ptDir){
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
	
	private void fire(){//Tank�����ӵ�   ���ӵ�һ���źţ������ӵ����Լ�ָ���ķ����ӵ�
		if(good)
			tc.times++;//ÿ�� ���ӵ���ʱ������һ��������

		int x = this.x + Tank.WIDTH/2 - Bullets.WIDTH/2;
		int y = this.y + Tank.HEIGHT/2 - Bullets.HEIGHT/2;
		Bullets b = new Bullets(x,y,ptDir,good,tc);
		
		if(!good)//�ط����˿���һֱ�����ӵ�
			tc.myBullets.add(b);
		else if(tc.times<30 && live){//������ҷ�̹�ˣ����ӵ���������20�Σ�����̹�˻��ţ���ô��װһ���ڵ�
			tc.myBullets.add(b);
		}//��������֤�ˣ����Լ����ӵ������ˣ��з������Է��ڵ�
	}
	private void fire(Direction dir){
		int x = this.x + Tank.WIDTH/2 - Bullets.WIDTH/2;
		int y = this.y + Tank.HEIGHT/2 - Bullets.HEIGHT/2;
		Bullets b = new Bullets(x,y,dir,good,tc);
		
		if(tc.times<30 && live){//������ҷ�̹�ˣ����ӵ���������80��
			tc.myBullets.add(b);
		}
	}
	
	private void superFire(){
		Direction[] arr = dir.values();//ת��Ϊ����
		for(int i = 0;i<8;i++){
			fire(arr[i]);
		}
		tc.times += 4;//�൱�ڸ�ɢ����һ���ӵ�  ��һ���൱����ǰ��4��
	}
	
	public Rectangle getRect(){
		return new Rectangle(x,y,WIDTH,HEIGHT);
	}
	
	public void hitWall(Wall w){//�ж��Ƿ�ײǽ
		if(live && this.getRect().intersects(w.getRect())){
			x = oldX;
			y = oldY;
		}
	}
	public void hitTank(java.util.List<Tank> tanks){
		for(int i = 0;i<tanks.size();i++){
			Tank t = tanks.get(i);
			if(this != t)//��һ���жϷǳ���Ҫ����Ȼ�Լ��϶����Լ��������ģ�ȫ��������
			if(live && this.getRect().intersects(tanks.get(i).getRect())){
				x = oldX;
				y = oldY;
			}
		}
	}
	
	public void eat(Blood b){
		if(this.live && this.getRect().intersects(b.getRect())){
			this.life = 100;
			b.setLive(false);
		}
	}
	
	private class BloodBar{
		public void draw(Graphics g){
			Color c = g.getColor();
			g.setColor(Color.red);
			g.drawRect(x, y-15, WIDTH, HEIGHT/4);
			int width = WIDTH * life/100;
			g.fillRect(x, y-15, width, HEIGHT/4);
			g.setColor(c);
		}
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
			
			case KeyEvent.VK_Q	   : fire(); break;//����Q���Ϳ��Ի�ȡ�ӵ�  ��λ�ú�  ̹�����ڵķ����ӵ��ķ���Ȼ�����paint�����ػ��ӵ�
			case KeyEvent.VK_R	   : superFire(); break;
			case KeyEvent.VK_SPACE : tc.times = 0; break;
			case KeyEvent.VK_F2    : if(!live) { live = true; life = 100;}//�������
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
