package com.dong.client;

import java.io.IOException;
import java.util.Scanner;

import com.dong.Server.Server;

public class Client {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true)
		{
			System.out.println("��¼�밴1\tע���밴2\t�˳��밴3");
			int b = input.nextInt();
			if(3 == b){
				break;
			}
			
			System.out.println("�������û�����");
			String name = input.next();
			System.out.println("���������루����10λ����");
			String pwd = input.next();
			if(1 == b){
				new Server().login(name, pwd);
			}else if(2 == b){
				System.out.println("�������Ա�(man or woman)��");
				String sex = input.next();
				new Server().register(name, pwd, sex);
			}
		}
		System.out.println("�����˳���");
	}
}
