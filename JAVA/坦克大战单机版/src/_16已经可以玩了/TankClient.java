
package _16�Ѿ���������;

import java.awt.*;
import java.awt.event.*;
import java.util.List;

import _16�Ѿ���������.Tank.Direction;

import java.util.ArrayList;
/*
 *  void setResizable(boolean resizable) 
          ���ô˴����Ƿ�����û�������С�� 
    
    public abstract Color getColor()��ȡ��ͼ�������ĵĵ�ǰ��ɫ��
    
    public abstract void setColor(Color c)����ͼ�������ĵĵ�ǰ��ɫ����Ϊָ����ɫ��ʹ�ô�ͼ�������ĵ����к���ͼ�β�����ʹ�����ָ������ɫ�� 
    
    public void repaint()�ػ������� 
	�����������������������˷����ᾡ����ô������ paint ����������˷����ᾡ����ô������ update ������
	
	abstract  boolean drawImage(Image img, int x, int y, ImageObserver observer) 
          ����ָ��ͼ���е�ǰ���õ�ͼ�� 

 */
public class TankClient extends Frame{
	private Image offScreamImage = null;
	public static final int WIDTH=800,HEIGHT=600;
	public int times = 0;//������ʾ���˼����ڵ�
	public List<Bullets> myBullets = new ArrayList<Bullets>();//�����м����ڵ�
	public List<Explode> explodes = new ArrayList<Explode>();
	public List<Tank> enemyTank = new ArrayList<Tank>();
	private Tank myTank = new Tank(50,500,true,Direction.STOP,this);//��TankClient���󴫽�ȥ��ʹTank���Բ���TankClient����Ĳ�������
	
	public void paint(Graphics g) {
		myTank.drawTank(g);
		for(int i=0 ;i<enemyTank.size();i++){//��������̹��
			Tank t = enemyTank.get(i);
			t.drawTank(g);
		}
		for(int i = 0;i<explodes.size();i++){//������ը
			Explode e = explodes.get(i);
			e.draw(g);
		}
		
		g.setFont(new Font("", Font.BOLD, 15));//��������
		if(times>=20){
			g.drawString("���ж��ٷ��ڵ�:"+0, 10, 50);
			g.setColor(Color.red);
//			g.setFont(new Font("", Font.BOLD, 20));
			g.drawString("û�ڵ���(��Ǯ)", 20, 75);
		}
		else{
			g.drawString("���ж��ٷ��ڵ�:"+(20-times), 10, 50);
			g.drawString("�з�̹�ˣ�"+enemyTank.size(), 10, 70);
		}
		
		if(myBullets.size()!=0)
		for(int i=0;i<myBullets.size();i++){
			Bullets b = myBullets.get(i);//������һ���ڵ�	��һ���ӵ������������з���
			b.hitTanks(enemyTank);//�ж��Ƿ����̹�ˣ������˾�����live��־Ϊfalse��
			b.hitTank(myTank);
			b.drawBullets(g);//������̹�ˣ��ӵ��Լ��Ͳ��ٻ��Լ��ˣ�ͨ��̹���Լ��ڲ���live��־��
		}
	}

	//���˫����������˸����
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

	
	public void lauchFrame(){
		this.setBounds(250,80,WIDTH,HEIGHT);
//		this.setResizable(false);//���ò����Ե�����С
		this.setBackground(Color.gray);
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		this.addKeyListener(myTank.new MyKeyEvent());
		
		for(int i = 1;i<10;i++){
			enemyTank.add(new Tank(50+40*i,50,false,Direction.STOP,this));
		}
		
		setVisible(true);
		
		new Thread(new PaintThread()).start();//����һ���̣߳��ػ�
	}
	
	public static void main(String[] args) {
		new TankClient().lauchFrame();
	}
	
	//�ڲ���
	private class PaintThread implements Runnable{
		public void run() {
			while(true){
				repaint();
				try {
					Thread.sleep(30);//ÿ80�����ػ�һ��
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
