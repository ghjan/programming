package _15;
/*
 * ʲôʱ���巺���ࣿ
 * ������Ҫ�����������������Ͳ�ȷ����ʱ��
 * ������Object�������չ
 * ���ڶ��巺���������չ
 */
class Worker{
	
}
class Tool{
	private Object obj;

	public Object getObj() {
		return obj;
	}

	public void setObj(Object obj) {
		this.obj = obj;
	}

}
//������
class Utils<QQ>{
	private QQ q;

	public QQ getQ() {
		return q;
	}

	public void setQ(QQ q) {
		this.q = q;
	}
	
}
public class ������ {
	public static void main(String[] args) {
//		Tool t = new Tool();
//		t.setObj(new Worker());
//		Worker w = (Worker)t.getObj();
		
		Utils<Worker> u = new Utils<Worker>();
		u.setQ(new Worker());
		Worker w = u.getQ();
	}
}
