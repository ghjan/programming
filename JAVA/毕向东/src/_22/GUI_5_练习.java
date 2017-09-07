package _22;

import java.awt.Button;
import java.awt.Dialog;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Label;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;

public class GUI_5_��ϰ {
	private Frame f;		//���
	private TextField tf;	//�ı���
	private TextArea ta;	//�ж��е��ı���(�ı���)
	private Button but;		//��ť
	private Dialog d ;		//�Ի���
	private Button okButton;//�Ի����еİ�ť
	private Label lab;		//��ǩ�����Ի�������ֵģ�
	GUI_5_��ϰ(){
		init();
	}
	public void init(){
		f = new Frame("My window");
		//��������
		f.setBounds(300,100,600,450);//����  ��ܣ�x , y ����   ��   �� ��
		f.setLayout(new FlowLayout());//��ʽ����
		tf = new TextField(50);//�ı���
		ta = new TextArea(18,70);//��18  70��   ���ı���  
		but = new Button("ת��");//��ť
		
		d = new Dialog(f,"��ʾ��Ϣ",true);//����һ���Ի���   ��һ�������ǹ���  Frame�ģ��������������Ϊtrue��ô��Dialog�Ի���ʱ�����ܶ�Frame��False�Ϳ��Զ�
		d.setBounds(500,300,350,100);//�Ի����е�λ��+��С
		d.setLayout(new FlowLayout());//��ʽ����
		lab = new Label(); //������治��ֱ��д�ı���Ҫ�ñ�ǩ
		okButton = new Button("  ȷ��    ");//�Ի����еİ�ť
		
		//������
		f.add(tf);//��ӵ�Frame
		f.add(but);
		f.add(ta);
		
		d.add(lab);//��ӵ�Dialog
		d.add(okButton);
		
		//��Ӵ����¼�
		myEvent();
		
		//�ɼ�
		f.setVisible(true);
	}
	
	private void myEvent(){
		//ʵ��Frame��� �Ĺرչ���
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.out.println("�˳�");
				System.exit(0);
			}
		});
		//ʵ��Dialog�Ի���Ĺرչ���
		d.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				d.setVisible(false);
			}
		});
		//ʵ��Dialog�Ի��򰴼�      ����ʱ�Ĺ��ܣ�ʹDialog�Ի�����ʧ����������ǻ�ģ����Լ�������Ҳ����
		okButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				d.setVisible(false);
			}
		});
		//�����ı���   ��������
		tf.addKeyListener(new KeyAdapter(){
			public void keyPressed(KeyEvent e){
				if(e.getKeyCode() == e.VK_ENTER)
					showDir();
			}
		});
		//���� ������ť�ʱ�Ĺ���
		but.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				showDir();
			}
		});
	}
	private void showDir(){
		String dirPath = tf.getText();//��ȡ�ı�����
		
		File dir = new File(dirPath);//���ı�����ת��Ϊ·��
		if(dir.exists() && dir.isDirectory()){//�ж�·���Ƿ����  �� �����Ŀ¼
			ta.setText("");//����ı�
			String[] names = dir.list();//��ȡ��·���µ��б�
			for(String name : names){//�����б�
				ta.append(name+"\n");//��׷�ӵķ�ʽд��
			}
		}
		else{//���û��Ŀ¼���������
			String info = "���������Ϣ����:"+dirPath+"������";
			lab.setText(info);
			d.setVisible(true);
		}
		tf.setText("");//ÿ���������ı����Զ����
	}
	public static void main(String[] args) {
		new GUI_5_��ϰ();
	}
}
/*	Window    ->    void addWindowListener(WindowListener l) ���ָ���Ĵ������������ԴӴ˴��ڽ��մ����¼���
              ->    WindowListener   ->     WindowAdapter 
              ->	void windowClosing(WindowEvent e)  ���������ڹرչ�����ʱ���á� 
              
	Button    ->	void addActionListener(ActionListener l)  ���ָ���Ķ������������Խ��շ��Դ˰�ť�Ķ����¼��� 
			  ->	ActionListener    ->    void actionPerformed(ActionEvent e)  ��������ʱ���á�
			  
	Component ->    void addKeyListener(KeyListener l)   ���ָ���İ������������Խ��շ��Դ�����İ����¼���
			  ->	KeyListener       ->	KeyAdapter
			  ->	void keyPressed(KeyEvent e)    ����ĳ����ʱ���ô˷����� 

 
           
 */
