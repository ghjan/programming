package _18;

import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class ����֮��ļ��� {
	public static void main1(String[] args) {
		//��ȡĳһ�������
		Calendar c = Calendar.getInstance();
		Scanner sc = new Scanner(System.in);
		int year = sc.nextInt();
		c.set(year,11,31);//�·��Ǵ�0��ʼ���������12��31��
		System.out.println(c.get(Calendar.DAY_OF_YEAR));//���ؽ��꿪ʼ��12��31��  ������
	}
	public static void main(String[] args) {
		//��ȡĳһ���2�·�����
		Calendar c = Calendar.getInstance();
		Scanner sc = new Scanner(System.in);
		int year = sc.nextInt();
		c.set(year, 2,1);//��������Ϊ3��1��
		c.add(Calendar.DAY_OF_MONTH, -1);//��ǰ���ڼ�һ��
		System.out.println(c.get(Calendar.DAY_OF_MONTH));//��ȡ��ȥ������������
		
	}
	
	//�Ӽ�������
	public static void main2(String[] args) {
		  Scanner sc = new Scanner(System.in); 
		  
		  
		    System.out.println("ScannerTest, Please Enter Name:"); 
		    String name = sc.nextLine();  //��ȡ�ַ��������� 
		    
		    System.out.println("ScannerTest, Please Enter Age:"); 
		    int age = sc.nextInt();    //��ȡ�������� 
		    
		    System.out.println("ScannerTest, Please Enter Salary:"); 
		    float salary = sc.nextFloat(); //��ȡfloat������ 
		    
		    
		    System.out.println("Your Information is as below:"); 
		    System.out.println("Name:" + name +"\n" + "Age:"+age + "\n"+"Salary:"+salary); 
	}
}
