package com.dong.Server;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Date;

import com.dong.entity.DbUser;
import com.dong.utils.DbUtils;

public class Server {
	private Connection conn;
	private PreparedStatement pState;
	private ResultSet rs;
	public void login(String name,String pwd){
		DbUser user = new DbUser();
		try {
			conn = DbUtils.getConnection();
			pState = conn.prepareStatement("select * from student where name=? and password=?");
			pState.setString(1, name);
			pState.setString(2, pwd);
			rs = pState.executeQuery();
			while(rs.next()){
				user.setName(rs.getString(2));
				user.setSex(rs.getString(4));
				user.setDate(rs.getString(5));
				System.out.println("��¼�ɹ���");
				System.out.println(user.toString());
				return;
			}
			System.out.println("�˺����벻��");
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	public void register(String name,String pwd,String sex){
		DbUser user = new DbUser();
		try {
			conn = DbUtils.getConnection();
			pState = conn.prepareStatement("INSERT INTO student VALUES(NULL,?,?,?,?)");
			pState.setString(1, name);
			pState.setString(2, pwd);
			pState.setString(3, sex);
			
			Date date= new Date();//����һ��ʱ����󣬻�ȡ����ǰ��ʱ��
			SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//����ʱ����ʾ��ʽ
			String str = sdf.format(date);//����ǰʱ���ʽ��Ϊ��Ҫ������
			System.out.println(str+"---------------------");
			pState.setString(4, str);
			
			if(pState.executeUpdate() > 0){
				System.out.println("�����ɹ�����");
				return;
			}
			System.out.println("����ʧ��");
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}
