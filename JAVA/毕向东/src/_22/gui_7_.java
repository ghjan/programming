package _22;

import java.awt.Button;
import java.awt.Color;
import java.awt.Dialog;
import java.awt.FileDialog;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Label;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.TextArea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/*
 * MenuBar�˵���		Ϊ�˽��ò˵����� Frame ������������Ե��øÿ�ܵ� setMenuBar ����
 */
public class gui_7_ {
	private Frame f;
	private MenuBar bar;
	private Menu fileMenu,fileMenu2,fileMenu3,fileMenu4;
	private MenuItem openItem,saveItem,closeItem1,closeItem2,haha;//Item��Ŀ������
	private TextArea ta;
	private FileDialog openDia,saveDia;
	private File file;
	private Dialog Dia;
	private Label lab;
	private Button okButton;
	gui_7_(){
		init();
	}
	public void init(){
		f = new Frame("�Լ����ļ��±������ܻ���ȫ�������............ֻ�ܼ򵥵Ĵ򿪣����棬�ر�.txt�ļ�������ע����.txt�ļ�");
		f.setBounds(300,100,900,550);
//		f.setLayout(new FlowLayout());
		
		bar = new MenuBar();//�����˵���
		fileMenu = new Menu(" �ļ�       ");//�����˵���
		fileMenu2 = new Menu("����ɶ��û����");
		fileMenu3 = new Menu("����˵��ɶ��û�л�����");
		fileMenu4 = new Menu("��ƭ�˰�");
		openItem = new MenuItem("�򿪡� ");
		saveItem = new MenuItem("����� ");
		closeItem1 = new MenuItem("�˳��� ");//�����˵���
		closeItem2 = new MenuItem("������");//�����˵���
		haha = new MenuItem("O(��_��)O����~");
		ta = new TextArea();
		Dia = new Dialog(f,"ȷ�����浽��ǰ�ļ�����ô",true);
		lab = new Label("O(��_��)O"); //������治��ֱ��д�ı���Ҫ�ñ�ǩ
		okButton = new Button("  ȷ��    ");//�Ի����еİ�ť
		
		f.setMenuBar(bar);//�ڿ������Ӳ˵���
		f.add(ta);
		bar.add(fileMenu);//�ڲ˵�������Ų˵���
		bar.add(fileMenu2);
		fileMenu.add(openItem);//�ڲ˵������淽�ţ�����Ŀ��
		fileMenu.add(saveItem);//�ڲ˵������淽�ţ�����Ŀ��
		fileMenu.add(closeItem1);//�ڲ˵������淽��close������Ŀ��
		fileMenu2.add(fileMenu3);
		fileMenu2.add(closeItem2);
		fileMenu3.add(fileMenu4);
		fileMenu4.add(haha);
		Dia.add(lab);//��ӵ�Dialog
		Dia.add(okButton);
		Dia.setBounds(500,300,300,100);//�Ի����е�λ��+��С
		Dia.setLayout(new FlowLayout());//��ʽ����
		
		openDia = new FileDialog(f,"��Ҫ��ɶ�������������㡣��������������Ҵ���",FileDialog.LOAD);//����  �����ļ��򿪶���
		saveDia = new FileDialog(f,"��㱣�档�������������������",FileDialog.SAVE);//���� �����ļ��������  ���ǵ���windows��Դ
		myEvent();
		
//		f.setBackground(Color.BLUE);
		f.setVisible(true);
	}
	//���������   	X 	 ʱ
	private void myEvent(){
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.out.println("�˳�");
				System.exit(0);
			}
		});
		//������  okButtonʱ
		okButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				//��   �ı����е�����  д�뵽 �ļ���
				try {
					BufferedWriter bufw = new BufferedWriter(new FileWriter(file));//���ı�д���ַ������
					String text = ta.getText();//��ȡ�ı������ַ���
					bufw.write(text);//���ļ���д���ı������ַ���
					bufw.close();
				} catch (IOException e2) {
					throw new RuntimeException();
				}
				Dia.setVisible(false);		//Ȼ���ڹر�   �Ի��򣬣���ò�Ҫ����仰  �ŵ���ǰ�棬��Ϊ�����û�б���ã���ô����Ի���Ͳ�����ʧ������BUG
			}
		});
		//�ѶԻ��� ��		X		��ť�������ã�������ʱ�͹رգ�
		Dia.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				Dia.setVisible(false);
			}
		});
		//�����ʱ�����Ķ���
		openItem.addActionListener(new ActionListener(){//��Ӷ�����������������
			public void actionPerformed(ActionEvent e){//����ִ�У�Perform��
				openDia.setVisible(true);//�򿪶Ի���java�Ѿ��ṩ����FileDialog��
				String dirPath = openDia.getDirectory();//��¼Ŀ¼
				String fileName = openDia.getFile();//��¼�ļ���
				if(dirPath == null || fileName == null)
					return ;
				ta.setText("");
				file = new File(dirPath,fileName);//����һ���ļ�����
				try {
					BufferedReader bufr = new BufferedReader(new FileReader(file));//���ַ��������ж�ȡ�ı�
					String line = null;
					int n = 0;
					while((line = bufr.readLine())!=null && n++<200)//��BufferedReader�ж�ȡһ������
						ta.append(line+"\r\n");//��ӡ���ı���
					
					bufr.close();//�ر�BufferedReader
				} catch (IOException e2) {
					throw new RuntimeException("��ȡʧ��");
				}
			}
		});
		//�������ʱ�����Ķ���
		saveItem.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				if(file==null){							//����������û��new һ�� File ��ô�ͻ�� <����Ի���>
					saveDia.setVisible(true);			//��ʾ����Ի���
					String dirPath = saveDia.getDirectory();
					String fileName = saveDia.getFile();
					if(dirPath == null || fileName == null)// ��ô�ͻ�ȡ��ǰ·�����ļ���
						return ;//������˱���  Ȼ���ֵ�X  ��ô��û��·�� 
					file = new File(dirPath,fileName);//Ȼ�� new һ�� file
				}
				Dia.setVisible(true);					//���ܳ����Ƿ���һ��file   ������ʾ���Ƿ񱣴桱  �� X ���൱��û�д�����save����ȷ��������okButton��ȥִ��
			}
		});
		//����ر�ʱ�����Ķ���
		closeItem1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				System.exit(0);
			}
		});
	}
	public static void main(String[] args) {
		new gui_7_();
	}
}
/*	MenuItem -> void addActionListener(ActionListener l) ���ָ���Ķ������������ԴӴ˲˵�����ն����¼�
    Dialog	 -> FileDialog 
          
    FileReader ���ڶ�ȡ�ַ�����Ҫ��ȡԭʼ�ֽ������뿼��ʹ�� FileInputStream��
    BufferedReader���ַ��������ж�ȡ�ı�
    
	public String readLine()
              throws IOException��ȡһ���ı��С�ͨ�������ַ�֮һ������Ϊĳ������ֹ������ ('\n')���س� ('\r') ��س���ֱ�Ӹ��Ż��С�
                ���أ������������ݵ��ַ������������κ�����ֹ��������ѵ�����ĩβ���򷵻� null
 
 */
