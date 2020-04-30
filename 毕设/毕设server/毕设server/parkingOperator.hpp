#ifndef  __PARKING_OPERTORO_HPP__
#define  __PARKING_OPERTORO_HPP__

#include"Comm.hpp"

int arr[ROW][COL] = {};

class Build
{
public:
	void menu()
	{
		cout << "*********************************************" << endl;
		cout << "*****************0.退出**********************" << endl;
		cout << "****1.车位布局*******2.便道布局**************" << endl;
		cout << "****3.充电区布局*****4.无任务停靠区布局******" << endl;
		cout << "***************5.区域线**********************" << endl;
		cout << "***************8.展示**********************" << endl;
		cout << "*********************************************" << endl;
	}

	void give(int arr[ROW][COL], int x, int y, int wide, int length, int index)
	{
		for (int i = x - wide + 1; i <= x; i++)//进行局部的赋值
		{
			for (int j = y; j <= y + length - 1; j++)
			if (index == 1)//车位
				arr[i][j] = 1;
			else if (index == 2)//便道
				arr[i][j] = 2;
			else if (index == 3)//充电区车位
				arr[i][j] = 3;
			else if (index == 4)//无任务小车停靠车位
				arr[i][j] = 4;
			else if (index == 5)//填充区域
				arr[i][j] = 5;
			else if (index == 0)//停车场区域界线
				arr[i][j] = 10;
		}
	}

	//FOREGROUND颜色只有四种：GREEN，BLUE，RED，INTENSIFY（加强）
	//  红色 + 绿色 = 黄色
	//	绿色 + 蓝色 = 青色
	//	红色 + 蓝色 = 品红
	//	红色 + 绿色 + 蓝色 = 白色
	//  0 = 黑色                8 = 灰色　　
	//	1 = 蓝色                9 = 淡蓝色       
	//	2 = 绿色                10 = 淡绿色       
	//	3 = 湖蓝色              11 = 淡浅绿色     
	//	4 = 红色                12 = 淡红色       
	//	5 = 紫色                13 = 淡紫色       
	//	6 = 黄色                14 = 淡黄色       
	//	7 = 白色                15 = 亮白色     

	void print(int arr[ROW][COL])
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				if (arr[i][j] == 1)//表示车位
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					//cout << 0;
					//cout << "@";
					//	cout << 0;
					cout << "■";

				}
				else if (arr[i][j] == 0)//无属性
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					//cout << 0;
					//cout << "@";
				
					cout << "■";
				}
				else if (arr[i][j] == 2)//便道
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					//	cout << 0;▩
					//cout << "@";
					cout << "■";
				}
				else if (arr[i][j] == 3)//充电区
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					//cout << 0;
					//cout << "@";
					cout << "■";
				}
				else if (arr[i][j] == 4)//无任务小车停靠区
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
					//cout << 0;
					//cout << "□";
					cout << "■";
				}
				else if (arr[i][j] == 5)//边界
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					//cout << 0;
					//cout << "@";
					cout << "■";
				}
				else if (arr[i][j] == 6)//预定车位
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					//cout << 0;
					//cout << "@";
					cout << "■";
				}
				else if (arr[i][j] == 7)//改车位已被占用
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					//cout << 0;
					//cout << "@";
					cout << "■";
				}
				else if (arr[i][j] == 10)//墙
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					//cout << 0;
					//cout << "@";
					cout << "■";
				}
			}
			if (j == COL)//对数组进行分行
				cout << endl;
		}
	}

	//void model(int arr[ROW][COL])
	//{
	//	int index = 0;
	//	while (1)
	//	{
	//		menu();
	//		cout << "请选择菜单功能" << endl;
	//		cin >> index;
	//		if (index == 0)
	//			break;
	//		else
	//		{
	//			cout << "请输入左下顶点的数组下标" << endl;
	//			int x, y;
	//			cin >> x >> y;
	//			cout << "请输入局部区域的长度与宽度" << endl;
	//			int wide, length;
	//			cin >> length >> wide;
	//			int err = 0;
	//			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
	//			{
	//				err = 1;
	//			}
	//			if (err == 0){
	//				give(arr, x, y, wide, length, index);//进行局部的赋值
	//				cout << "数组展示:" << endl;//数组展示
	//				print(arr);
	//			}
	//			else{
	//				cout << "输入区域不存在" << endl;
	//			}
	//		}
	//	}
	//}	

	//void model(int arr[ROW][COL])
	//{
	//	int index ;
	//	while (1)
	//	{
	//		menu();
	//		cout << "请选择菜单功能" << endl;
	//		cin >> index;
	//		FILE* fp;
	//	
	//		if (index == 0)
	//			break;
	//		else if (index == 8)
	//			print(arr);
	//		else if (index == 2)
	//		{
	//			FILE* fp;
	//			fp = fopen("便道.txt", "r");
	//			while (1)
	//			{				
	//				//	cout << "请输入左下顶点的数组下标" << endl;
	//				int x, y;
	//				fscanf(fp, "%d", &x);
	//				fscanf(fp, "%d", &y);
	//				if (x < 0)
	//					break;
	//				//cout << "请输入局部区域的长度与宽度" << endl;
	//				int wide, length;
	//				fscanf(fp, "%d", &length);
	//				fscanf(fp, "%d", &wide);
	//				int err = 0;
	//				if ((x - wide + 1 < 0) || (y + length - 1 > COL))
	//				{
	//					err = 1;
	//				}
	//				if (err == 0){
	//					give(arr, x, y, wide, length, 2);//进行局部的赋值
	//					//	cout << "数组展示:" << endl;//数组展示
	//					//	print(arr);
	//				}
	//				else{
	//					//cout << "输入区域不存在" << endl;
	//				}
	//			}	
	//			fclose(fp);
	//		}
	//		else if (index == 1)
	//		{
	//			FILE* fp;
	//			fp = fopen("车位.txt", "r");
	//			while (1)
	//			{
	//				//	cout << "请输入左下顶点的数组下标" << endl;
	//				int x, y;
	//				fscanf(fp, "%d", &x);
	//				fscanf(fp, "%d", &y);
	//				if (x < 0)
	//					break;
	//				//cout << "请输入局部区域的长度与宽度" << endl;
	//				int wide, length;
	//				fscanf(fp, "%d", &length);
	//				fscanf(fp, "%d", &wide);
	//				int err = 0;
	//				if ((x - wide + 1 < 0) || (y + length - 1 > COL))
	//				{
	//					err = 1;
	//				}
	//				if (err == 0){
	//					give(arr, x, y, wide, length, 1);//进行局部的赋值
	//					//	cout << "数组展示:" << endl;//数组展示
	//					//	print(arr);
	//				}
	//				else{
	//					//cout << "输入区域不存在" << endl;
	//				}
	//			}
	//			//print(arr);
	//			fclose(fp);
	//		}
	//		else if (index == 3)
	//		{
	//			FILE* fp;
	//			fp = fopen("充电区.txt", "r");
	//			while (1)
	//			{
	//				//	cout << "请输入左下顶点的数组下标" << endl;
	//				int x, y;
	//				fscanf(fp, "%d", &x);
	//				fscanf(fp, "%d", &y);
	//				if (x < 0)
	//					break;
	//				//cout << "请输入局部区域的长度与宽度" << endl;
	//				int wide, length;
	//				fscanf(fp, "%d", &length);
	//				fscanf(fp, "%d", &wide);
	//				int err = 0;
	//				if ((x - wide + 1 < 0) || (y + length - 1 > COL))
	//				{
	//					err = 1;
	//				}
	//				if (err == 0){
	//					give(arr, x, y, wide, length, 3);//进行局部的赋值
	//					//	cout << "数组展示:" << endl;//数组展示
	//					//	print(arr);
	//				}
	//				else{
	//					//cout << "输入区域不存在" << endl;
	//				}
	//			}
	//			fclose(fp);
	//		}
	//		else if (index == 4)
	//		{
	//			FILE* fp;
	//			fp = fopen("小车停靠区.txt", "r");
	//			while (1)
	//			{
	//				//	cout << "请输入左下顶点的数组下标" << endl;
	//				int x, y;
	//				fscanf(fp, "%d", &x);
	//				fscanf(fp, "%d", &y);
	//				if (x < 0)
	//					break;
	//				//cout << "请输入局部区域的长度与宽度" << endl;
	//				int wide, length;
	//				fscanf(fp, "%d", &length);
	//				fscanf(fp, "%d", &wide);
	//				int err = 0;
	//				if ((x - wide + 1 < 0) || (y + length - 1 > COL))
	//				{
	//					err = 1;
	//				}
	//				if (err == 0){
	//					give(arr, x, y, wide, length, 4);//进行局部的赋值
	//					//	cout << "数组展示:" << endl;//数组展示
	//					//	print(arr);
	//				}
	//				else{
	//					//cout << "输入区域不存在" << endl;
	//				}
	//			}
	//			fclose(fp);
	//		}
	//		else if (index == 5)
	//		{
	//			FILE* fp;
	//			fp = fopen("区域线.txt", "r");
	//			while (1)
	//			{				
	//				//	cout << "请输入左下顶点的数组下标" << endl;
	//				int x, y;
	//				fscanf(fp, "%d", &x);
	//				fscanf(fp, "%d", &y);
	//				if (x < 0)
	//					break;
	//				//cout << "请输入局部区域的长度与宽度" << endl;
	//				int wide, length;
	//				fscanf(fp, "%d", &length);
	//				fscanf(fp, "%d", &wide);
	//				int err = 0;
	//				if ((x - wide + 1 < 0) || (y + length - 1 > COL))
	//				{
	//					err = 1;
	//				}
	//				if (err == 0){
	//					give(arr, x, y, wide, length, 5);//进行局部的赋值
	//					//	cout << "数组展示:" << endl;//数组展示
	//					//	print(arr);
	//				}
	//				else{
	//					//cout << "输入区域不存在" << endl;
	//				}
	//				//print(arr);
	//			}	
	//			fclose(fp);
	//		}
	//	}
	//}

	void model(int arr[ROW][COL])
	{
		FILE* fp1;
		fp1 = fopen("便道.txt", "r");
		while (1)
		{
			//	cout << "请输入左下顶点的数组下标" << endl;
			int x, y;
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			int wide, length;
			fscanf(fp1, "%d", &length);
			fscanf(fp1, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 2);//进行局部的赋值
				//	cout << "数组展示:" << endl;//数组展示
				//	print(arr);
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp1);

		

		FILE* fp3;
		fp3 = fopen("区域线.txt", "r");
		while (1)
		{
			//	cout << "请输入左下顶点的数组下标" << endl;
			int x, y;
			fscanf(fp3, "%d", &x);
			fscanf(fp3, "%d", &y);
			if (x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			int wide, length;
			fscanf(fp3, "%d", &length);
			fscanf(fp3, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 5);//进行局部的赋值
				//	cout << "数组展示:" << endl;//数组展示
				//	print(arr);
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp3);

		FILE* fp2;
		fp2 = fopen("充电区1.txt", "r");
		while (1)
		{
			//	cout << "请输入左下顶点的数组下标" << endl;
			int x, y;
			fscanf(fp2, "%d", &x);
			fscanf(fp2, "%d", &y);
			if (x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			int wide, length;
			fscanf(fp2, "%d", &length);
			fscanf(fp2, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 3);//进行局部的赋值
				//	cout << "数组展示:" << endl;//数组展示
				//	print(arr);
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp2);

		FILE* fp6;
		fp6 = fopen("充电区2.txt", "r");
		while (1)
		{
			int x, y;
			fscanf(fp6, "%d", &x);
			fscanf(fp6, "%d", &y);
			if (x < 0)
				break;
			int wide, length;
			fscanf(fp6, "%d", &length);
			fscanf(fp6, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 3);//进行局部的赋值
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp6);

		FILE* fp4;
		fp4 = fopen("小车停靠区1.txt", "r");
		while (1)
		{
			//	cout << "请输入左下顶点的数组下标" << endl;
			int x, y;
			fscanf(fp4, "%d", &x);
			fscanf(fp4, "%d", &y);
			if (x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			int wide, length;
			fscanf(fp4, "%d", &length);
			fscanf(fp4, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 4);//进行局部的赋值
				//	cout << "数组展示:" << endl;//数组展示
				//	print(arr);
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp4);

		FILE* fp7;
		fp7 = fopen("小车停靠区2.txt", "r");
		while (1)
		{
			//	cout << "请输入左下顶点的数组下标" << endl;
			int x, y;
			fscanf(fp7, "%d", &x);
			fscanf(fp7, "%d", &y);
			if (x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			int wide, length;
			fscanf(fp7, "%d", &length);
			fscanf(fp7, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 4);//进行局部的赋值
				//	cout << "数组展示:" << endl;//数组展示
				//	print(arr);
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp7);


		FILE* fp5;
		fp5 = fopen("车位1.txt", "r");
		while (1)
		{
			//	cout << "请输入左下顶点的数组下标" << endl;
			int x, y;
			fscanf(fp5, "%d", &x);
			fscanf(fp5, "%d", &y);
			if (x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			int wide, length;
			fscanf(fp5, "%d", &length);
			fscanf(fp5, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 1);//进行局部的赋值
				//	cout << "数组展示:" << endl;//数组展示
				//	print(arr);
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp5);

		FILE* fp8;
		fp8 = fopen("车位2.txt", "r");
		while (1)
		{
			//	cout << "请输入左下顶点的数组下标" << endl;
			int x, y;
			fscanf(fp8, "%d", &x);
			fscanf(fp8, "%d", &y);
			if (x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			int wide, length;
			fscanf(fp8, "%d", &length);
			fscanf(fp8, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 1);//进行局部的赋值
				//	cout << "数组展示:" << endl;//数组展示
				//	print(arr);
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp8);

		FILE* fp9;
		fp9 = fopen("共用车位.txt", "r");
		while (1)
		{
			//	cout << "请输入左下顶点的数组下标" << endl;
			int x, y;
			fscanf(fp9, "%d", &x);
			fscanf(fp9, "%d", &y);
			if (x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			int wide, length;
			fscanf(fp9, "%d", &length);
			fscanf(fp9, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 1);//进行局部的赋值
				//	cout << "数组展示:" << endl;//数组展示
				//	print(arr);
			}
			else{
				//cout << "输入区域不存在" << endl;
			}
		}
		fclose(fp9);
		give(arr, 80, 95, 10,1, 0);
	}
	   

};




#endif