package com.dong.login;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.dong.entity.dbUser;
import com.dong.util.DbUtils;

public class ServerUp {
	//Server�������bug   һ�ֽС�sqlע�롱�Ķ������ƻ���  �������������������ʱ�����      ' or '1'='1   �ͻ����bug
	//	SELECT * FROM day06 WHERE NAME='jfdsaio' AND PASSWORD='aa' or '1'='1';��or����ƻ�		
	public dbUser findUser(String name, String pwd) {
		Connection conn = null;
		PreparedStatement preState = null;//�����������������������
		ResultSet rs = null;
		dbUser u = null;
		try {
			conn = DbUtils.getConnection();
			//ʹ��sql����Ԥ���빦��
			String sql = "SELECT * FROM day06 WHERE NAME=? AND PASSWORD=?";
			preState = conn.prepareStatement(sql);//�õ�ִ��sql���Ķ���Statement
			//������ֵ
			preState.setString(1, name);
			preState.setString(2, pwd);
			//preState.setInt(3, fiosadjf);  �����int��ô�������
			rs = preState.executeQuery();
			
			
			if (rs.next()) {// �����������ô�ڶ���һ����Ϊ��
				u = new dbUser();
				u.setId(rs.getInt(1));
				u.setName(rs.getString(2));
				u.setScore(rs.getInt(3));
				u.setTime(rs.getDate(4));
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			DbUtils.closeAll(rs, preState, conn);
		}
		return u;
	}
}
