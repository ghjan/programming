package _20;

import java.io.File;

public class IO_4_�ݹ��г�Ŀ¼���������� {
	public static void main(String[] args) {
		File dir = new File("E:\\study_materials\\JAVA\\����");
		showDir(dir);
	}
	
	public static void showDir(File dir){
		File[] files = dir.listFiles();
		for(int x = 0;x<files.length;x++){
			System.out.println(files[x]);//��ӡ��Ŀ¼
			//�ж��Ƿ���Ŀ¼
			if(files[x].isDirectory())//�ݹ����
				showDir(files[x]);
		}
	}
	
}
