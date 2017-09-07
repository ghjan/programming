package _16;

import java.util.*;
/*
 * ΪʲôStudents����ҪhashCode ��equals  ������
 * ��Ϊ  Students û����λ HashMap��key����ֵ��������HashMap�ļ�ֵ�ǣ�String������� ����������Լ���HashCode��equals����
 */
class Students{
	private String name;
	private int id;
	
	Students(String name,int id){
		this.name = name;
		this.id  = id;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String toString(){
		return name+"      "+id;
	}
}
public class map_5_��ϰ {
	public static void main(String[] args) {
		HashMap<String,List<Students>> czbk = new HashMap<String,List<Students>>();//�����һ����
		
		List<Students> yure = new ArrayList<Students>();//�����һ�����  ѧ��
		List<Students> jiuye = new ArrayList<Students>();
		
		czbk.put("1yureban", yure);//��һ������� HashMap������	
		czbk.put("2jiuyeban", jiuye);
		
		yure.add(new Students("����",01));//��һ�����з�ѧ��
		yure.add(new Students("����",02));
		jiuye.add(new Students("����",01));
		jiuye.add(new Students("����",02));
		
		for(Iterator<String> it = czbk.keySet().iterator();it.hasNext();){
			String roomNmae = it.next();//ȡ�����Զ���İ༶��key��
			List<Students> room =  czbk.get(roomNmae);//ȡ���Ǿ����ĳһ���ࣨValue��
			
			System.out.println(roomNmae);
			
			for(Iterator<Students> it2 = room.iterator();it2.hasNext();){//������༶������б���������ÿһ��ѧ��
				Students s = it2.next();
				System.out.println(s.getName()+"      "+s.getId());
			}
		}
	}
}
