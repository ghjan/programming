
package _4;

import java.awt.*;
import java.awt.event.*;
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
	private int x=50 , y=50;
	private static final int WIDTH=800,HEIGHT=600;
	private Image offScreamImage = null;
	
	public void paint(Graphics g) {
		Color c = g.getColor();//��ȡ��ͼ�������ĵĵ�ǰ��ɫ��
		g.setColor(Color.blue);
		g.fillOval(x, y, 30, 30);
		
		g.setColor(c);//����ͼ�������ĵĵ�ǰ��ɫ����Ϊָ����ɫ
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
	
//	//�ü̳еķ���  ʵ�ּ��̼�����   ����ڽӿڣ���������д��������
//	private class KeyMonitor extends KeyAdapter{//KeyAdapter implements KeyListener
//		public void keyPressed(KeyEvent e) {
//			System.out.println("dong");
//		}
//	}

	public void lauchFrame(){
		this.setBounds(250,80,WIDTH,HEIGHT);
		this.setResizable(false);//���ò����Ե�����С
		this.setBackground(Color.gray);
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		this.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent e) {
				int key = e.getKeyCode();
				switch(key){
				case KeyEvent.VK_UP    : y-=5;break;//ע�����ﲻ����e.VK_UP  e�Ǳ����ˣ����ܳ��ֱ���
				case KeyEvent.VK_DOWN  : y+=5;break;
				case KeyEvent.VK_RIGHT : x+=5;break;
				case KeyEvent.VK_LEFT  : x-=5;break;
				}
			}
		});
		
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
//				try {
//					Thread.sleep(1000);//ÿ80�����ػ�һ��
//				} catch (InterruptedException e) {
//					e.printStackTrace();
//				}
			}
		}
	}
}
