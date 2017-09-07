package _25;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
/**
 * ��ը��
 * @author ���
 *
 */
public class Explode {//��ը
	private int x , y;
	private boolean live = true;
	private int step = 0;//�����ڼ�����
	private TankClient tc;
	private static boolean init;
	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Image[] image = {
			tk.getImage(Explode.class.getClassLoader().getResource("images/0.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/1.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/2.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/3.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/4.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/5.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/6.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/7.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/8.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/9.gif")),
			tk.getImage(Explode.class.getClassLoader().getResource("images/10.gif"))
	};
	
	Explode(int x,int y,TankClient tc){
		this.x = x;
		this.y = y;
		this.tc = tc;
	}
	
	public void draw(Graphics g){
		if(!init){
			for (int i = 0; i< image.length; i++) {//�ᷢ�ֵ�һ�δ���ˣ�������ֱ�ը��������ϵͳ��һ�� ����ͼƬ��ʱ�򲻻�ŵ��ڴ���
				g.drawImage(image[i], 100, 100, null);
			}
			init = true;
		}
		
		if(!live){
			tc.explodes.remove(this);//����ը�������ˣ��ʹ�TankClient�ı�ը�������Ƴ���ǰ��ը
			return ;
		}
		if(step==11){
			this.live = false;
			this.step = 0;
			return ;
		}
		g.drawImage(image[step++], x, y, null);
	}
}
