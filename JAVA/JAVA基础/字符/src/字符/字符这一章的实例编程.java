package �ַ�;
import java.util.*;
public class �ַ���һ�µ�ʵ����� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true){
		String originalUserName = "12";
		String orginalPassword = "12";
		//��������
		Scanner s = new Scanner(System.in);
		String name = s.nextLine();
		String Pwd = s.nextLine();
		if(!name.equals(originalUserName)){
			System.out.println("���û�\n");
			continue;
		}
		if(!Pwd.equals(orginalPassword)){
			System.out.println("�������\n");
			continue;
		}
		System.out.println("ͨ��");		
		}
	}

}
