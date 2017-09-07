package _22;

import java.awt.*;
import java.awt.event.*;
/*
 * Component
 */
public class GUI_4_�������¼� {
	private Frame f;
	private Button but1,but2;
	private TextField tf;
	GUI_4_�������¼�(){
		init();
	}
	
	public void init(){
		f = new Frame("My Frame");
		
		//��Frame���мƱ�����
		f.setBounds(300,100,600,500);
		
		f.setLayout(new FlowLayout());
		but1 = new Button("my button1");
		but2 = new Button("my button2");
		tf   = new TextField(20);
		//�������ӵ�Frame��
		f.add(but1);
		f.add(but2);
		f.add(tf);
		
		//���ش����¼�
		myEvent();
		
		//��ʾ
		f.setVisible(true);
	}
	
	private void myEvent(){
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.out.println("�˳�");
				System.exit(0);
			}
		});
		//�ð�ť�߱����������
		/*���ģ�Component-> void addMouseListener(MouseListener l) ���ָ����������������Խ��շ��Դ����������¼� 
		 * 		->MouseListener->MouseAdapter(������)
		 * 					  void mouseEntered(MouseEvent e)           �����뵽�����ʱ���á� 
		 * 					  void mousePressed(MouseEvent e)           ��갴��������ϰ���ʱ���á� ���á�
 							  void mouseWheelMoved(MouseWheelEvent e)    ��������תʱ���á�
 			->MouseEvent->    int getClickCount()       ��������¼���������굥��������
     
		 */
		but1.addMouseListener(new MouseAdapter(){
//			public void mouseEntered(MouseEvent e){
//				System.out.println("����������");
//			}
			public void mousePressed(MouseEvent e){
				if(e.getClickCount() == 3)
					System.out.println("��������---");
				else if(e.getClickCount() == 2)
				System.out.println("˫������");
			}
			public void mouseWheelMoved(MouseWheelEvent e){
				System.out.println("��������תʱ���á�");
			}
		});
		but1.addActionListener(new ActionListener(){//�������������ǣ�����������������˰�ť�����������꣬����Ҳ�����ǰ�ť�
			public void actionPerformed(ActionEvent e){
				System.out.println("��ť���");
			}
		});
		//��but2���һ�����̼���
		but2.addKeyListener(new KeyAdapter(){
			public void keyPressed(KeyEvent e){
				System.out.println(KeyEvent.getKeyText(e.getKeyCode())+"      "+e.getKeyCode());
				if(e.getKeyCode() == KeyEvent.VK_ENTER && e.isControlDown())// boolean isControlDown()  ���� Control ���η��ڴ��¼�����Ϊ down 
					System.exit(0);
			}
		});
		
		//����ı�����̼���
		tf.addKeyListener(new KeyAdapter(){
			public void keyPressed(KeyEvent e){
				int code = e.getKeyCode();
				if(!(code>=KeyEvent.VK_0 && code<=KeyEvent.VK_9 || code>=KeyEvent.VK_NUMPAD0 && code<=KeyEvent.VK_NUMPAD9)){//ֻ��������0 - 9
					System.out.println(KeyEvent.getKeyText(code)+"     �Ƿ�");
					e.consume();//void consume() ʹ�ô��¼����Ա㲻�ᰴ��Ĭ�ϵķ�ʽ�ɲ������¼���Դ������������¼��� 
				}
			}
		});
	}
	
	public static void main(String[] args) {
		new GUI_4_�������¼�();
	}
}
