package ��;

class Point{
	public int x = 0;
	public int y = 0;
	public Point (int a,int b){
		x=a;
		y=b;
	}
}
class Rectangle{
	public int width=0;
	public int height=0;
	public Point origin;//����һ��Point ����
	public Rectangle(Point p,int w,int h){
		origin = p;
		width = w;
		height = h ;
	}
}


public class ��Ķ��� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Point originOne = new Point(23,94);		//����һ��Point ����
		Rectangle rectone = new Rectangle(originOne,100,200);// ����һ�� Rectangle ����
		System.out.println(rectone.origin.x);
		System.out.println(rectone.origin.y);
		System.out.println(rectone.height);
		System.out.println(rectone.width);		
	}

}
