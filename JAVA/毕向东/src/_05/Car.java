package _05;

public class Car{
	//������ɫ
	String color = "red";						// color ���Ǿֲ�����
	//������̥�ĸ���
	int num = 4;
	//������Ϊ��������
	void run(){
		System.out.println("��ɫ��"+color+"\n��̥����"+num);
	}
	
	//�ӿ� Source->Generate Getters and Setters
	public String getColor() {
		return color;
	}
	public void setColor(String color) {
		this.color = color;
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	
}