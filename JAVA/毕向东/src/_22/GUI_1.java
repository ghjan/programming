package _22;

import java.awt.*;
/*
 * ����ͼ�λ����棺
 * 1������Frame����
 * 2���Դ�����мƱ����á����磺λ�ã���С������
 * 3���������
 * 4�������ͨ�������add������ӵ�������
 * 5���ô�����ʾ����setVisible������
 */
public class GUI_1 {
	public static void main(String[] args) {
		Frame f = new Frame("hello world");
		f.setLocation(400,200);
		f.setSize(500,400);
		f.setLayout(new FlowLayout());//������ʽ����
		
		Button b = new Button("����һ����ť");//Ĭ�ϱ߽�ʽ���
		f.add(b);
		
		f.setVisible(true);
		
	}
}
