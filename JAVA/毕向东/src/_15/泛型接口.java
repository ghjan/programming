package _15;

interface Inter<T>{
	void show(T t);
}
class InterImpl<T> implements Inter<T>{
	public void show(T t){
		System.out.println(t);
	}
}
public class ���ͽӿ� {
	public static void main(String[] args) {
		new InterImpl().show("haha");
		new InterImpl().show(132);
	}
}
