package _07;
/*
 * �ӿ������еķ����������Ĭ���� public �ģ��ڽӿ��п��Բ�д����������ʵ�ֽӿڵķ���Ȩ�޲��ܵ��ڽӿڵķ���Ȩ��
 * 
 * �ӿڵ����ã�
 * ������չ����Ĺ���
 */
abstract class Student1{
	public abstract void study();//ÿ��ѧ��������ѧϰ
}
//��һ��ѧ����һ���������̣��Ⱦƣ��������Ǿ��ǽӿ���
interface Smoking{
	void Smoke();
}
interface Drinking{
	void Drink();
}

class Wang extends Student1 implements Smoking,Drinking{
	public void study(){}								//��Ϊһ��ѧ������ѧϰ
	public void Smoke(){}								//��ͬѧ���Լ�����Ϊ  �磺����
	public void Drink(){}								//��ͬѧ���Լ�����Ϊ  �磺�Ⱦ�
}
class Li extends Student1 implements Drinking{
	public void study(){}								//��Ϊһ��ѧ������ѧϰ
	public void Drink(){}								//��ͬѧ���Լ�����Ϊ  �磺�Ⱦ�
}

public class �ӿ� {

}
