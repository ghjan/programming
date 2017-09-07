package JDBC;

import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

/**
 * ���ǳ��õĲ������ݿ�����SQL�� ����ִ�е�ʱ����ҪҪ�ȱ��룬Ȼ��ִ�У�
 * ���洢���̣�Stored Procedure����һ ��Ϊ������ض����ܵ�SQL��伯���������洢�����ݿ��У�
 * �û�ͨ��ָ���洢���̵����ֲ���������������ô洢���̴��в� ����������ִ������
 * 
 * �������̾��ǣ��洢����
 * ����Ҫ��mysql �в���ã�Ȼ����java����õ����
 * mysql> delimiter &		//�ı�������Ϊ &
 * mysql> create procedure Dong(in setAge int,out ave double)			//in �Ǵ�����ı���   out����ȡ��������
    -> reads sql data													//�̶�
    -> begin
    -> select Avg(score) into ave from user where age>setAge;		//��Ϊ������Ҫһ��;������ ��������Ҫ�ĳ� &������
    -> end &
Query OK, 0 rows affected (0.00 sec)
 * mysql> delimiter ;		//�ָ��� ;
 * 
 * @author ���
 *
 */
public class _2���ݿ�洢���� {
	public static void main(String[] args) {
		try {
			//1.��������
			Class.forName("com.mysql.jdbc.Driver");
			//2.��ȡ����Connection
			Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test","root","dong");
//			//ע���������
			CallableStatement callstatement = conn.prepareCall("{call Dong(?,?)}");//���Ǵ������м��������Ĵ洢���̾�Ҫ��������
			callstatement.setInt(1, 24);//���õ�һ������
			callstatement.registerOutParameter(2, java.sql.Types.DOUBLE);
			callstatement.execute();
			String average = String.format("%.1f", callstatement.getDouble(2));//�õ����
			System.out.println("student average score:" + average);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

