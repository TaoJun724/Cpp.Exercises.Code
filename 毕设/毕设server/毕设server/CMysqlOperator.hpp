#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <WinSock.h>  //一定要包含这个，或者winsock2.h
#include <mysql.h>//引入mysql头文件(一种方式是在vc目录里面设置，一种是文件夹拷到工程目录，然后这样包含)
#include <Windows.h>
#include<iostream>
#include<string.h>
using namespace std;

//包含附加依赖项，也可以在工程--属性里面设置
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")
MYSQL mysql; //mysql连接
MYSQL_FIELD *fd;  //字段列数组
char field[32][32];  //存字段名二维数组
MYSQL_RES *res; //这个结构代表返回行的一个查询结果集
MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
char query[150]; //查询语句



class CMysqlOperatoe
{
public:
	//连接数据库
	bool ConnectDatabase()
	{
		//初始化mysql
		mysql_init(&mysql);  //连接mysql，数据库
		//返回false则连接失败，返回true则连接成功
		if (!(mysql_real_connect(&mysql, "localhost", "root", "17382572860", "parkinglot", 3306, NULL, 0)))
			//中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
		{
			//printf("Error connecting to database:%s\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			//printf("Connected...\n");
			return true;
		}
	}

	//释放资源
	void FreeConnect()
	{
		//释放资源
		mysql_free_result(res);
		mysql_close(&mysql);
	}

	/***************************数据库操作***********************************/
	//查询数据
	bool QueryDatabase1()
	{
		sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以
		mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
		//返回0 查询成功，返回1查询失败
		if (mysql_query(&mysql, query))        //执行SQL语句
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf("query success\n");
		}
		//获取结果集
		if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}
		//打印数据行数
		printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
		//获取字段的信息
		char *str_field[32];  //定义一个字符串数组存储字段信息
		for (int i = 0; i<3; i++)   //在已知字段数量的情况下获取字段名
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i<3; i++)   //打印字段
			printf("%10s\t", str_field[i]);
		printf("\n");
		//打印获取的数据
		while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
		{
			printf("%10s\t%10s\t%10s\t\n", column[0], column[1], column[2]);  //column是列数组
		}
		return true;

	}

	bool QueryDatabase2()
	{
		sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以
		mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
		//返回0 查询成功，返回1查询失败
		if (mysql_query(&mysql, query))        //执行SQL语句
		{
		//	printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
		//	printf("query success\n");
		}
		//获取结果集
		if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}
		//打印数据行数
		printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
		//获取字段的信息
		char *str_field[32];  //定义一个字符串数组存储字段信息
		for (int i = 0; i<3; i++)   //在已知字段数量的情况下获取字段名
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i<3; i++)   //打印字段
			printf("%10s\t", str_field[i]);
		printf("\n");
		//打印获取的数据
		while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
		{
			printf("%10s\t%10s\t%10s\t\n", column[0], column[1], column[2]);  //column是列数组
		}
		return true;
	}


	//修改数据
	bool ModifyData(char* sql)
	{
		sprintf(query, sql);
		if (mysql_query(&mysql, query))        //执行SQL语句
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf("ModifyData success\n");
			return true;
		}
	}

	//删除数据
	bool DeleteData(const char * sql)
	{
		char SQl[1024];
		sprintf_s(SQl, sql);
		if (mysql_query(&mysql, sql) != 0)
		{
			cerr << "执行sql语句失败，错误信息为： " << mysql_error(&mysql) << endl;
			return false;
		}
		return true;
	}


	//插入数据
	bool InsertDate(const char * sql)
	{
		mysql_query(&mysql, "set names gbk");
		if (mysql_query(&mysql, sql))
		{
			// 打错误log，这里直接显示到控制台
			cerr << "执行sql语句失败，错误信息为： " << mysql_error(&mysql) << endl;
			return false;
		}
		else
		{
			cout << "执行sql语句成功！" << endl;
		}

		return true;
	}


};


//数据库操作测试
//int main()
//{
//	CMysqlOperatoe m;
//	mysql_query(&mysql, "set names gbk");
//	m.ConnectDatabase();
//	char* SQL = "Insert into userInfo(licensePlate, userName, passwd) values('陕A42244', '思思', '123456');";
//	m.InsertDate(SQL);
//	m.QueryDatabase1();
//	//SQL = "Update userInfo set userName = '张大三' where userName = '张三'";
//	//m.ModifyData(SQL);
//	//m.QueryDatabase1();
//
//	//char* SQL = "delete from userInfo where delete_licensePlate = '陕B44444'";
//  /*  const 	char* SQL = "delete from userInfo where userName = 'aa'";
//	m.DeleteData(SQL);
//	m.QueryDatabase1();*/
//	m.FreeConnect();
//	system("pause");
//
//	return 0;
//
//}