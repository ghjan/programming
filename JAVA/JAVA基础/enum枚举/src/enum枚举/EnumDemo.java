package enumö��;

enum Season{		//����Season ö������
	��,��,��,��			// ������Կ��� JAVA ������ ASCII ��  ������ unicode 
}
public class EnumDemo{
	Season season;			//�������� season
	public EnumDemo(Season season){			//����һ�� Seson���͵Ĳ���
		this.season = season;
	}
	public void saySeason(){			//�������
		switch (season){
			case ��:System.out.println("�����Ǵ���.");
			break;
			case ��:System.out.println("�������ļ�.");
			break;
			case ��:System.out.println("�������＾.");
			break;
			case ��:System.out.println("�����Ƕ���.");
			break;
		}
	}
}
//����
class Test{
	public static void main(String[] args){
		EnumDemo spring = new EnumDemo (Season.��);		//���� һ���µ� ���� ʵ��
		spring.saySeason();								// ���� saySeason
		EnumDemo summer = new EnumDemo (Season.��);
		summer.saySeason();
		EnumDemo fall = new EnumDemo (Season.��);
		fall.saySeason();
		EnumDemo winter = new EnumDemo (Season.��);
		winter.saySeason();
	}
}
