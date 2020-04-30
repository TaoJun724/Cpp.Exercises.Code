#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARINGS
#include<stdio.h>
#include<winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include <string.h>
#include"Comm.hpp"
#include"parkingMember.hpp"
#include"parkingOperator.hpp"
#include"CMysqlOperator.hpp"
#include "CMysqlOperator.hpp"
using namespace std;
#pragma comment(lib,"ws2_32.lib")
#define MaxClient 10
#define MaxBufSize 1024
const int PORT = 8000;
Manage m;
map<string, string> plsql;
CMysqlOperatoe sql;


//服务线程
DWORD WINAPI ServerThread(LPVOID lpParameter){
	bool flag;
	bool flag1;
	bool flag2;
	bool flag3;
	string licensestr;
//	m.initParking();
	mysql_query(&mysql, "set names gbk");
	sql.ConnectDatabase();
	sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	//返回0 查询成功，返回1查询失败
	mysql_query(&mysql, query);      //执行SQL语句
	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		//	printf("Couldn't get result from %s\n", mysql_error(&mysql));
		//	return false;
	}
	//获取字段的信息
	char *str_field[32];  //定义一个字符串数组存储字段信息
	for (int i = 0; i<3; i++)   //在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
		//printf("%10s\t%10s\t%10s\t\n", column[0], column[1], column[2]);  //column是列数组
		plsql.insert(make_pair(column[0], column[2]));
	}

	SOCKET *ClientSocket = (SOCKET*)lpParameter;
	int receByt = 0;
	char revData[MaxBufSize];
//	char sendData[MaxBufSize];
	while (1){
		receByt = recv(*ClientSocket, revData, sizeof(revData), 0);
		if (receByt>0){
			cout << "接收到的消息是：" << revData << "            来自客户端:" << *ClientSocket << endl;
		}
		else
		{
			cout << "接收消息结束！" << endl;
			break;
		}

		//事件流处理		
		string str(revData);
		string str1;
		str1 = str.substr(0, 20);
		const char* str2;
		str2 = str1.c_str();

		string str6;
		str6 = str.substr(0, 13);
		const char* str7;
		str7 = str6.c_str();
		//发送数据给客户端
		char sendData[1024];



		/************请进行管理员功能选择***************\n
		******1.查询数据库**********2.删除数据库******\n
		******3.查询车位状态********4.查询便道状态****\n
		******5.查询小车状态********6.展示停车场******\n
		     ********6.退出登录******\n\n*/
		if (strcmp(revData, "管理员") == 0)
		{
			flag2 = true;
			send(*ClientSocket, "请输入管理员密码\n", sizeof(sendData), 0);
		}
		else if (flag2 == true)
		{
			if (strcmp(revData, "admin") == 0)
			{
				flag2 = false;
				send(*ClientSocket, "管理员登录成功\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
			}
			else{
				send(*ClientSocket, "密码错误，请重新输入管理员密码\n", sizeof(sendData), 0);
			}

		}
		else if ((strcmp(revData, "查询数据库") == 0))
		{
			sql.QueryDatabase1();
			send(*ClientSocket, "\n数据库已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "查询小车状态") == 0))
		{
			int noWork = m.findAgvCarStatus();
			if (noWork < AgvCarNum){
				//工作小车返回坐标 //待完成
			}
			send(*ClientSocket, "\n小车状态已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "删除数据库") == 0)
		{
			flag3 = true;
			send(*ClientSocket, "请输入删除的车牌号\n", sizeof(sendData), 0);
		}
		else if (flag3 == true)
		{
			string str4("delete from userInfo where licensePlate = '");
			str4 += str;
			string str5("'");
			str4 += str5;
			const char* SQL = str4.c_str();
			sql.DeleteData(SQL);
			sql.QueryDatabase1();
			flag3 = false;
			send(*ClientSocket, "\n数据库删除操作完成\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "用户") == 0)
		{
			send(*ClientSocket, "\n**************************************************\n**********1.用户注册**********2.用户登录**********\n**************************************************\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "用户登录") == 0)
		{
			flag = true;
			send(*ClientSocket, "请输入你的车牌号\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "用户注册") == 0)
		{
			flag1 = true;
			send(*ClientSocket, "请输入你的车牌号，姓名，登录密码\n", sizeof(sendData), 0);
		}
		else if (flag1 == true)
		{
			char *temp;
			char *output = revData;
			string licenseplate;
			string name;
			string passed;
			int index = 1;
			while ((temp = strchr(output, ',')) != NULL) {
				*temp = '\0';
				if (index == 1){
					licenseplate = output;
					index++;
				}
				else if (index == 2){
					name = output;
				}
				output = temp + 1;
			}
			passed = output;
			plsql.insert(make_pair(licenseplate, passed));
			string SQL("Insert into userInfo(licensePlate, userName, passwd) values('");
			SQL += licenseplate;
			string fuhao("','");
			string fuhao1("');");
			SQL += fuhao;
			SQL += name;
			SQL += fuhao;
			SQL += passed;
			SQL += fuhao1;
			const char* sq = SQL.c_str();
			sql.InsertDate(sq);
			flag1 = false;
			send(*ClientSocket, "注册成功\n\n**************************************************\n**********1.用户注册**********2.用户登录**********\n**************************************************\n", sizeof(sendData), 0);
		}
		else if (licensestr.size() == 0 && flag == true)
		{
			licensestr += str;
			send(*ClientSocket, "请输入你的密码\n", sizeof(sendData), 0);
		}
		else if (flag == true && licensestr.size() != 0)
		{
			string password = plsql[licensestr];
			const char *licenseindex = password.c_str();
			if (strcmp(licenseindex, revData) == 0)
			{
				flag = false;
				licensestr.clear();
				send(*ClientSocket, "用户登陆成功\n\*******请进行用户功能选择*********\n******1.停车**********2.取车******\n      ******3.退出登录********\n\n", sizeof(sendData), 0);
			}
			else{
				//flag = false;
				licensestr.clear();
				send(*ClientSocket, "车牌或者密码错误，请重新输入车牌号\n", sizeof(sendData), 0);
			}

		}
		else if ((strcmp(revData, "查询车位状态") == 0))
		{
			m.findParkingSpaceStatus();
			send(*ClientSocket, "\n车位状态已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "查询便道状态") == 0))
		{
			m.findRoadStatus();
			send(*ClientSocket, "\n便道状态已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "展示停车场") == 0))
		{
			m.show();
			send(*ClientSocket, "停车场已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "退出登录") == 0))
		{
			send(*ClientSocket, "退出成功\n\n************请选择你的身份:******************\n*************1.管理员********2.用户**********\n*********************************************\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "取车") == 0)
		{
			send(*ClientSocket, "取车功能待实现\n\n*******请进行用户功能选择*********\n******1.停车**********2.取车******\n******3.退出登录********\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "停车") == 0)
		{
			send(*ClientSocket, "停车功能待实现\n\n*******请进行用户功能选择*********\n******1.停车**********2.取车******\n******3.退出登录********\n\n", sizeof(sendData), 0);
		}
		else
		{
			send(*ClientSocket, "无效操作\n", sizeof(sendData), 0);
		}
	}
	closesocket(*ClientSocket);
	free(ClientSocket);
	return 0;
}



int main(){
	m.initParking();
	WSAData wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ListenAddr;
	ListenAddr.sin_family = AF_INET;
	ListenAddr.sin_addr.S_un.S_addr = INADDR_ANY;//表示填入本机ip
	ListenAddr.sin_port = htons(PORT);
	int n;
	n = bind(ListenSocket, (LPSOCKADDR)&ListenAddr, sizeof(ListenAddr));
	if (n == SOCKET_ERROR){
		cout << "端口绑定失败！" << endl;
		return -1;
	}
	else{
		cout << "端口绑定成功：" << PORT << endl;
	}
	int l = listen(ListenSocket, 20);
	cout << "服务端准备就绪，等待连接请求" << endl;

	while (1){
		//循环接收客户端连接请求并创建服务线程
		SOCKET *ClientSocket = new SOCKET;
		ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
		//接收客户端连接请求
		int SockAddrlen = sizeof(sockaddr);
		*ClientSocket = accept(ListenSocket, 0, 0);
		cout << "一个客户端已连接到服务器，socket是：" << *ClientSocket << endl;
		CreateThread(NULL, 0, &ServerThread, ClientSocket, 0, NULL);
	}//while
	closesocket(ListenSocket);
	WSACleanup();
	system("pause");
	return(0);
}//main

