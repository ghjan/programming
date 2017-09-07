
package _10;

import java.awt.*;
import java.awt.event.*;
import java.util.List;
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
	private Tank myTank = new Tank(50,50,this);//��TankClient���󴫽�ȥ��ʹTank���Բ���TankClient����Ĳ�������
	public static final int WIDTH=800,HEIGHT=600;
	public List<Bullets> myBullets = new ArrayList<Bullets>();//�����м����ڵ�
	
	public void paint(Graphics g) {
		myTank.drawTank(g);
		
		g.setFont(new Font("", Font.PLAIN, 20));//��������
		if(myBullets.size()>=20){
			g.drawString("���ж��ٷ��ڵ�:"+0, 10, 50);
			g.setColor(Color.red);
			g.setFont(new Font("", Font.BOLD, 20));
			g.drawString("û�ڵ���", 20, 80);
		}
		else
		g.drawString("���ж��ٷ��ڵ�:"+(20-myBullets.size()), 10, 50);
		
		if(myBullets.size()!=0 && myBullets.size()<=20)
		for(int i=0;i<myBullets.size();i++){
			Bullets b = myBullets.get(i);//������һ���ڵ���Ȼ�󻭳������Ͳ������ˡ�
			b.drawBullets(g);
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
		this.setResizable(false);//���ò����Ե�����С
		this.setBackground(Color.gray);
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		this.addKeyListener(myTank.new MyKeyEvent());
		
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
					Thread.sleep(20);//ÿ80�����ػ�һ��
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
