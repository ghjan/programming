package �ӿ�;

interface A{
	float PI = 3.14f;
	float getArea();
}
interface B{
	float PI = 3.1415f;
	float getArea();
}
class Area implements A,B{
	private float radius;
	Area(){
		radius = 0;
	}
	Area(float r){
		radius = r;
	}
	public float getArea(){
		float area = A.PI * radius * radius;// A.PI��ʾ��A�ӿڵ�PI
		return area;
	}
}

public class ����ӿڳ���������ͻ {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Area a = new Area();
		float area = a.getArea();
		System.out.println(area);
		
		a = new Area(1);
		area = a.getArea();
		System.out.println(area);
	}

}
