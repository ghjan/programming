
package _25;

import java.awt.*;
import java.awt.event.*;
import java.util.List;

import java.util.ArrayList;
/**
 * ���������Ϸ�������ڣ������඼����������
 * @author ���
 *
 */
public class TankClient extends Frame{
	private Image offScreamImage = null;
	public static int WIDTH,HEIGHT;
	public int times = 0;//������ʾ���˼����ڵ�
	public List<Bullets> myBullets = new ArrayList<Bullets>();//�����м����ڵ�
	public List<Explode> explodes = new ArrayList<Explode>();
	public List<Tank> enemyTank = new ArrayList<Tank>();
	public Tank myTank = new Tank(50,500,true,Direction.STOP,this);//��TankClient���󴫽�ȥ��ʹTank���Բ���TankClient����Ĳ�������
	
	public int width = Toolkit.getDefaultToolkit().getScreenSize().width;
	public int height = Toolkit.getDefaultToolkit().getScreenSize().height;
	
	public Wall wall1 = new Wall(100,100,20,200,this);
	public Wall wall2 = new Wall(400,450,100,70,this);
	public Blood b = new Blood(this);
	private boolean GAME_OVER = false;
	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Image image = tk.getImage(TankClient.class.getClassLoader().getResource("images/tank.gif"));
	
	/**
	 * �������ʱ����ͼ�ε���Ҫ������������ʵ�ֵ�ͼ�Σ����ն�Ҫ�ŵ����������
	 */
	public void paint(Graphics g) {
		g.drawImage(image, 0, 0, 1100, 600,null);

		wall1.draw(g);
		wall2.draw(g);
		b.draw(g);
		myTank.drawTank(g);
		myTank.eat(b);

		/**
		 * ������û���ˣ���������һЩ����
		 */
		if(enemyTank.size()==0){
			int reinitTank = Integer.parseInt(GetProp.getProp("reTankCount"));
			for(int i = 0;i<reinitTank;i++){
				Tank t = new Tank(50+80*i,50,false,Direction.STOP,this);
				t.GAME_LEVEL -= 3 ;
				enemyTank.add(t);
			}
		}
		/**
		 * ÿ��25������ػ��ط�����̹��
		 */
		for(int i=0 ;i<enemyTank.size();i++){//��������̹��
			Tank t = enemyTank.get(i);
			t.hitWall(wall1);
			t.hitWall(wall2);
			t.hitTank(enemyTank);//�з�̹�˲��ܻ�����ײ
//			myTank.hitTank(enemyTank);//ʹ�ҷ�̹��Ҳ���ܺȵз�̹��������������е�����  �Ժ��о���
			t.drawTank(g);
		}
		/**
		 * ������ը
		 */
		for(int i = 0;i<explodes.size();i++){
			Explode e = explodes.get(i);
			e.draw(g);
		}
		/**
		 *  ���û�����ʾ��Ϣ
		 */
		g.setFont(new Font("", Font.BOLD, 15));//��������
		g.setColor(Color.red);
		if(times>=30){
			g.drawString("���ж��ٷ��ڵ�:"+0, 10, 50);
			g.drawString("û�ڵ���(��Ǯ)", 20, 75);
		}
		else{
			g.drawString("���ж��ٷ��ڵ�:"+(30-times), 10, 50);
			g.drawString("�з�̹�ˣ�"+enemyTank.size(), 10, 70);
		}
		/**
		 * ���ӵ������ӵ�û���ˣ��Ͳ��ܻ��ӵ���
		 */
		if(myBullets.size()!=0)
		for(int i=0;i<myBullets.size();i++){
			Bullets b = myBullets.get(i);//������һ���ڵ�	��һ���ӵ������������з���
			b.hitTanks(enemyTank);//�ж��Ƿ����̹�ˣ������˾�����live��־Ϊfalse��
			b.hitTank(myTank);
			b.hitWall(wall1);//�����ӵ�ײǽʱ�Ķ���
			b.hitWall(wall2);//�����ӵ�ײǽʱ�Ķ���
			b.draw(g);//������̹�ˣ��ӵ��Լ��Ͳ��ٻ��Լ��ˣ�ͨ��̹���Լ��ڲ���live��־��
		}
	}

	/**
	 * ���˫����������˸����
	 */
	public void update(Graphics g) {
		if(offScreamImage == null){
			offScreamImage = this.createImage(WIDTH,HEIGHT);//�����ж�������������ͼƬ��
		}
			
		Graphics gOffScream = offScreamImage.getGraphics();//��ȡ����ͼƬ�Ļ���
		//�������ػ���Ļ��ʹ���ָ�ԭ������ɫ
		Color c = g.getColor();
		gOffScream.setColor(Color.gray);
		gOffScream.fillRect(0, 0, WIDTH, HEIGHT);
		gOffScream.setColor(c);
		
		paint(gOffScream);//����paint������ʹ����ͼƬҲ����   paint���������ͼƬ
		
		g.drawImage(offScreamImage, 0, 0, null);
	}

	/**
	 * ����ʼ��������
	 */
	public void lauchFrame(){
		//��ȡ��Ļ��Ϣ
		Toolkit kit = Toolkit.getDefaultToolkit();
		Dimension size = kit.getScreenSize();
		WIDTH = size.width/2+size.width/4;
		HEIGHT = size.height/2+size.height/4;
		this.setBounds(size.width/8,size.height/8,WIDTH,HEIGHT);
		
		Image image = kit.getImage("1.jpg");
		setIconImage(image);
		
//		this.setResizable(false);//���ò����Ե�����С
//		this.setBackground(Color.gray);//���ñ���
//		setUndecorated(true);//�ѱ�����ȥ��
//		setUndecorated(true);//ȫ��
//		getGraphicsConfiguration().getDevice().setFullScreenWindow(this);
		
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				GAME_OVER = true;
				System.exit(0);
			}
		});
		this.addKeyListener(myTank.new MyKeyEvent());
		
		//ʹ�������ļ�
		int initTankCount = Integer.parseInt(GetProp.getProp("initTankCount"));
		for(int i = 1;i<initTankCount;i++){
			enemyTank.add(new Tank(50+50*i,50,false,Direction.STOP,this));
		}
		
		setVisible(true);
		
		new Thread(new PaintThread()).start();//����һ���̣߳��ػ�
	}
	
	public static void main(String[] args) {
		new TankClient().lauchFrame();
	}
	
	/**
	 * �ػ���һ���߳�
	 * @author ���
	 *
	 */
	private class PaintThread implements Runnable{
		public void run() {
			while(!GAME_OVER){
				repaint();
				try {
					Thread.sleep(25);//ÿ80�����ػ�һ��
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
/*//��ȡ��Ļ��Ϣ
   Toolkit kit = Toolkit.getDefaultToolkit();
   Dimension size = kit.getScreenSize();
   int screenWidth = size.width;
   int screenHeight = size.height;
   //���ô��ڿ��
   jf.setSize(screenWidth/4, screenHeight/4);
   jf.setLocation(screenWidth/4, screenHeight/4);
   //����ͼ��
   Image image = kit.getImage("smile.gif");
   jf.setIconImage(image);
   
   
 	void setResizable(boolean resizable) 
          ���ô˴����Ƿ�����û�������С�� 
    
    public abstract Color getColor()��ȡ��ͼ�������ĵĵ�ǰ��ɫ��
    
    public abstract void setColor(Color c)����ͼ�������ĵĵ�ǰ��ɫ����Ϊָ����ɫ��ʹ�ô�ͼ�������ĵ����к���ͼ�β�����ʹ�����ָ������ɫ�� 
    
    public void repaint()�ػ������� 
	�����������������������˷����ᾡ����ô������ paint ����������˷����ᾡ����ô������ update ������
	
	abstract  boolean drawImage(Image img, int x, int y, ImageObserver observer) 
          ����ָ��ͼ���е�ǰ���õ�ͼ�� 
 */
