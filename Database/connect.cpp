/*��ϰmysql���ݿ������*/
#include <stdio.h>
#include <mysql/mysql.h>

int main()
{
	MYSQL mysql;
	int t, r;
	/*����֮ǰ������mysql_init��ʼ��MYSQL���Ӿ��*/
	mysql_init(&mysql);
	/*ʹ��mysql_real_connect���ӷ�����,���������ΪMYSQL�����������IP��ַ��
	��¼mysql���û��������룬Ҫ���ӵ����ݿ��*/
	if(!mysql_real_connect(&mysql, "localhost", "root", "dong", "mysql", 0, NULL, 0)) {
		printf("Error connecting to Mysql!\n");
	}else {
		printf("Connected Mysql successful!\n");
	}
	/*�ر�����*/
	mysql_close(&mysql);
	return 0;
}