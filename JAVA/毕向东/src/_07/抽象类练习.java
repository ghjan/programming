package _07;
/**
 * �������ͨԱ���ĳ�������ϰ
 * @author ���
 *
 */
abstract class Employes{
	private String name;
	private String id;
	private int pay;
	
	Employes(String name,String id,int pay){//��ͨԱ���;������е�����
		this.name = name;
		this.id = id;
		this.pay  = pay;
	}
	
	public abstract void work();		//��ͨԱ���;�������һ��
	
	void show(){								//չ�ֳ����� ��ͬ����
		System.out.println("name is : "+name);
		System.out.println("id is : "+id);
		System.out.println("pay is : "+pay);
	}
}

class Manager extends Employes{
	private int bonus;
	Manager(String name,String id,int pay,int bonus){
		super( name, id, pay);
		this.bonus = bonus;
	}
	public void work(){
		System.out.println("Manager work");
	}
	public void show(){							//����չ�ֳ����ı���ͨԱ����һ��	����
		super.show();
		System.out.println("bonus is : "+bonus);
	}
}

class ComEmployes extends Employes{
	ComEmployes(String name,String id,int pay){
		super(name,id,pay);
	}
	public void work(){
		System.out.println("ComEmpolyes work");
	}
}


public class ��������ϰ {
	public static void main(String[] args) {
		Manager M = new Manager("cmd","M9870000123",100000,9999);
		ComEmployes C = new ComEmployes("dong","C70000123",9999);
		M.show();
		System.out.println();
		C.show();
	}
}
