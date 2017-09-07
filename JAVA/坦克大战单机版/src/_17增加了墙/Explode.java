package _17������ǽ;

import java.awt.*;

public class Explode {//��ը
	private int x , y;
	private boolean live = true;
	private int[] diameter = {2,5,10,20,25,25,18,10,5,2};//diameterֱ��
	private int step = 0;//�����ڼ�����
	private TankClient tc;
	
	Explode(int x,int y,TankClient tc){
		this.x = x;
		this.y = y;
		this.tc = tc;
	}
	
	public void draw(Graphics g){
		if(!live){
//						 remove(Object o) �Ƴ����б����״γ��ֵ�ָ��Ԫ�أ�������ڣ��� 
			tc.explodes.remove(this);//����ը�������ˣ��ʹ�TankClient�ı�ը�������Ƴ���ǰ��ը
			return ;
		}
		if(step==diameter.length){
			this.live = false;
//			this.step = 0;
			return ;
		}
		
		Color c = g.getColor();
		g.setColor(Color.orange);
		g.fillOval(x++, y, diameter[step], diameter[step++]);
		g.setColor(c);
	}
	
}
