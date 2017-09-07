/*��ϰmysql���ݿ������*/
#include <stdio.h>
#include <mysql.h>

int main()
{
	MYSQL mysql;
	int t, r;
	/*����֮ǰ������mysql_init��ʼ��MYSQL���Ӿ��*/
	mysql_init(&mysql);
	/*ʹ��mysql_real_connect���ӷ�����,���������ΪMYSQL�����������IP��ַ��
	��¼mysql���û��������룬Ҫ���ӵ����ݿ��*/
	if(!mysql_real_connect(&mysql, "localhost", "root", "6748355", "spytest", 0, NULL, 0)) {
		printf("Error connecting to Mysql!\n");
	}else {
		printf("Connected Mysql successful!\n");
	}
	/*�ر�����*/
	mysql_close(&mysql);
	return 0;
}


/*��ϰmysql���ݿ�Ĳ�ѯ*/
#include <stdio.h>
#include <string.h>
#include "mysql.h"


int main()
{
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *query;
	int flag, t;
	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql, "localhost", "root", "dong", "plane", 0, NULL, 0)) {
		printf("Failed to connect to Mysql!\n");
		return 0;
	}else {
		printf("Connected to Mysql successfully!\n");
	}
	query = "select * from test2";
	/*��ѯ���ɹ��򷵻�0*/
	flag = mysql_real_query(&mysql, query, (unsigned int)strlen(query));
	if(flag) {
		printf("Query failed!\n");
		return 0;
	}else {
		printf("[%s] made...\n", query);
	}


	/*mysql_store_result��ȫ���Ĳ�ѯ�����ȡ���ͻ���*/
	res = mysql_store_result(&mysql);
	/*mysql_fetch_row�������������һ��*/
	while(row = mysql_fetch_row(res)) {
		/*mysql_num_fields���ؽ�����е��ֶ���Ŀ*/
		for(t=0; t<mysql_num_fields(res); t++)
		{
			printf("%s\t", row[t]);
		}
		printf("\n");
	}
	mysql_close(&mysql);
	return 0;
}


/*��ϰmysql���ݿ���������*/
#include <stdio.h>
#include <string.h>
#include "mysql.h"


int main()
{
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *query;
	int flag, t;
	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql, "localhost", "root", "dong", "spytest", 0, NULL, 0)) {
		printf("Failed to connect to Mysql!\n");
		return 0;
	}else {
		printf("Connected to Mysql successfully!\n");
	}
	query = "insert into log(title, keyword, content) values('sleep', 'rest', 'I have a dream')";
	/*���룬�ɹ��򷵻�0*/
	flag = mysql_real_query(&mysql, query, (unsigned int)strlen(query));
	if(flag) {
		printf("Insert data failure!\n");
		return 0;
	}else {
		printf("Insert data success!\n");
	}


	mysql_close(&mysql);
	return 0;
}


/*��ϰmysql���ݿ��ɾ��*/
#include <stdio.h>
#include <string.h>
#include "mysql.h"

int main()
{
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *query;
	int flag, t;
	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql, "localhost", "root", "6748355", "spytest", 0, NULL, 0)) {
		printf("Failed to connect to Mysql!\n");
		return 0;
	}else {
		printf("Connected to Mysql successfully!\n");
	}
	query = "delete from log where log_id=3";
	/*ɾ�����ɹ��򷵻�0*/
	flag = mysql_real_query(&mysql, query, (unsigned int)strlen(query));
	if(flag) {
		printf("Delete data failure!\n");
		return 0;
	}else {
		printf("Delete data success!\n");
	}

	mysql_close(&mysql);
	return 0;
}