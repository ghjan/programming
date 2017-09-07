package JDBC;

import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.text.SimpleDateFormat;

import org.junit.Test;

public class _1���� {
	@Test
	public void test1() {
		try {
			//1.��������
			Class.forName("com.mysql.jdbc.Driver");
			//2.��ȡ����Connection
			Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/school","root","dong");
			//3.���sql���ִ�ж���  Statement
			Statement statement = conn.createStatement();
			//4.ִ��sql��䣬�����ؽ��
			String sql = "insert into student values(2,222,'С��','woman','1996-2-2','ɳ����ɳĮ')";
			int res = statement.executeUpdate(sql);
			if(res > 0){
				System.out.println("����ɹ�");
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	@Test
	public void test3() {
		try {
			//1.��������
			Class.forName("com.mysql.jdbc.Driver");
			//2.��ȡ����Connection
			Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/school","root","dong");
			//3.���sql���ִ�ж���  Statement
			Statement statement = conn.createStatement();
			//4.ִ��sql��䣬�����ؽ��
			String sql = "delete from student where id=2";
			int res = statement.executeUpdate(sql);
			if(res > 0){
				System.out.println("ɾ���ɹ�");
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	@Test
	public void test2() {
		//1.��������
		try {
			Class.forName("com.mysql.jdbc.Driver");
			//2.��ȡ����Connection
			Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/school","root","dong");
			//3.���sql���ִ�ж���  Statement
			Statement statement = conn.createStatement();
			//4.ִ��sql��䣬�����ؽ��
			String sql = "select * from student";
			ResultSet res = statement.executeQuery(sql);
			while(res.next()){
				System.out.println(res.getInt(1)+"\t"+res.getInt(2)+"\t"+res.getObject(3)+"\t"+res.getObject(4)+"\t"+res.getObject(5)+"\t"+res.getObject(6));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	@Test
	public void test4() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/school","root","dong");
			PreparedStatement pState = conn.prepareStatement("insert into student values(?,?,?,?,?,?)");
			pState.setInt(1, 3);
			pState.setInt(2, 333);
			pState.setString(3, "chen");
			pState.setString(4, "man");
			pState.setString(5, "1996-2-22");
			pState.setString(6, "America");
			pState.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
}
