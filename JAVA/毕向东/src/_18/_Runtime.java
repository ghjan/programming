package _18;

import java.io.IOException;

/*
 * Runtime
 * ������new ����
 * ���Ҹ����л��зǾ�̬����
 * ˵������϶����ṩ�˷�����ȡ������󣬶��Ҹ÷����Ǿ�̬��
 * 
 * ����ʹ���˵������ģʽ
 */
public class _Runtime {
	public static void main(String[] args) throws Exception {
		Runtime r = Runtime.getRuntime();
//		r.exec("E:\\programming\\JAVA\\exe�ļ�\\file\\����ר�ü��±�.exe");
		r.exec("notepad.exe E:\\programming\\JAVA\\����\\src\\_18\\_Runtime.java");
	}
}
