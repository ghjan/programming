package _20;

import java.io.File;
import java.io.FilenameFilter;

public class IO_3_file�ļ��б� {
	public static void main1(String[] args) {
		File[] files = File.listRoots();
		for(File f: files){			//�������̣��̷�
			System.out.println(f);
			
			String[] names = f.list();
			for(String name:names)//����ÿ���̷��µ�Ŀ¼  �����������ļ���
				System.out.println(name);
		}
	}
	public static void main2(String[] args) {
		File dir = new File("E:\\programming\\C");
		String[] arr = dir.list(new FilenameFilter(){//������Filter		���˵�false..ֻ����true;
			public boolean accept(File dir,String name){
				return name.endsWith(".exe");//�����.exe��β��ô����true   ����Ϊfalse    
			}
		});
		for(String name : arr){
			System.out.println(name);
		}
	}
	public static void main(String[] args) {
		//�������Ǹ�ʵ����һ��������������Ƿ��ص�File		�ļ����󡣡������Ǹ�ֻ�Ƿ����ļ������֣��ַ�����
		File dir = new File("E:\\study_materials\\JAVA\\����\\��20��");
		File[] files = dir.listFiles();
		for(File f:files)
			System.out.println(f.getName()+"    ��С��"+f.length()/1024/1024+"M");//ͨ���ļ��������ǲ������Ի�ȡ�ļ��������ҿ��Ի�ȡ��С��
	}
	
}
