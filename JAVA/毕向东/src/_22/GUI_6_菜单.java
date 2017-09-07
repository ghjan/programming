package _22;

import java.awt.FileDialog;
import java.awt.Frame;
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
public class GUI_6_�˵� {
	private Frame f;
	private MenuBar bar;
	private Menu fileMenu;
	private MenuItem openItem,saveItem,closeItem;//Item��Ŀ������
	private TextArea ta;
	private FileDialog openDia,saveDia;
	private File file;
	GUI_6_�˵�(){
		init();
	}
	public void init(){
		f = new Frame("my window");
		f.setBounds(300,100,650,600);
//		f.setLayout(new FlowLayout());
		
		bar = new MenuBar();//�����˵���
		fileMenu = new Menu("�ļ�");//�����˵���
		openItem = new MenuItem("��");
		saveItem = new MenuItem("����");
		closeItem = new MenuItem("�˳�");//�����˵���
		ta = new TextArea();
		
		f.setMenuBar(bar);//�ڿ������Ӳ˵���
		f.add(ta);
		bar.add(fileMenu);//�ڲ˵�������Ų˵���
		fileMenu.add(openItem);//�ڲ˵������淽�ţ�����Ŀ��
		fileMenu.add(saveItem);//�ڲ˵������淽�ţ�����Ŀ��
		fileMenu.add(closeItem);//�ڲ˵������淽��close������Ŀ��
		
		
		openDia = new FileDialog(f,"��Ҫ��",FileDialog.LOAD);
		saveDia = new FileDialog(f,"��Ҫ����",FileDialog.SAVE);
		
		myEvent();
		
		f.setVisible(true);
	}
	private void myEvent(){
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.out.println("�˳�");
				System.exit(0);
			}
		});
		
		openItem.addActionListener(new ActionListener(){//��Ӷ�����������������
			public void actionPerformed(ActionEvent e){//����ִ�У�Perform��������
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
					while((line = bufr.readLine())!=null)//��BufferedReader�ж�ȡһ������
						ta.append(line+"\n");//��ӡ���ı���
					bufr.close();//�ر�BufferedReader
					
				} catch (IOException e2) {
					// TODO: handle exception
					throw new RuntimeException("��ȡʧ��");
				}
			}
		});
		saveItem.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				if(file==null){
					saveDia.setVisible(true);
					
					String dirPath = saveDia.getDirectory();
					String fileName = saveDia.getFile();
					if(dirPath == null || fileName == null)
						return ;
					file = new File(dirPath,fileName);//����һ���ļ�����
				}
				try {
					BufferedWriter bufw = new BufferedWriter(new FileWriter(file));//���ı�д���ַ������
					String text = ta.getText();//��ȡ�ı������ַ���
					bufw.write(text);//���ļ���д���ı������ַ���
					bufw.close();
				} catch (IOException e2) {
					throw new RuntimeException();
				}
			}
		});
		
		
		closeItem.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				System.exit(0);
			}
		});
	}

	
	public static void main(String[] args) {
		new GUI_6_�˵�();
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
