package _1;

import java.awt.*;
import java.awt.event.*;
/*
 *  void setResizable(boolean resizable) 
          ���ô˴����Ƿ�����û�������С�� 
 */
public class TankClient extends Frame{
	
	public void lauchFrame(){
		this.setBounds(250,100,800,600);
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		this.setResizable(false);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new TankClient().lauchFrame();
	}
}
