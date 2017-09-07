package _2;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
/*
 * getText()���ش��ı������ʾ���ı�
 *  String trim() �����ַ����ĸ���������ǰ���հ׺�β���հס� 
 */
public class ChatClient extends Frame{
	TextField tf = new TextField();
	TextArea ta = new TextArea();
	
	public void launchFrame(){
		setBounds(400,100,600,500);
		
		add(tf,BorderLayout.SOUTH);
		add(ta,BorderLayout.NORTH);
		pack();
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		tf.addActionListener(new TFListener());//����TestField����
		setVisible(true);
	}
	
	private class TFListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			String s = tf.getText().trim();
			ta.setText(s);
			tf.setText("");
		}
		
	}
	
	public static void main(String[] args) {
		new ChatClient().launchFrame();
	}
	
	
	
}
