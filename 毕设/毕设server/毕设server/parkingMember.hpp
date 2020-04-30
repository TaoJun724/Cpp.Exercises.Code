#ifndef  __PARKING_MEMBER_HPP__
#define  __PARKING_MEMBER_HPP__

#include"Comm.hpp"
#include"parkingOperator.hpp"

class agvCar//AGV小车类
{
public:
	void change1(int x, int y)//当车位状态变为预定时进行改值
	{
		int i = x;
		int j = y;
		int length = 0;
		int index = 1;
		while (arr[i][j] == 1)
		{
			arr[i][j] = 6;
			j++;
		}
		length = j - y;
		if (length == 9)
		{
			j = y; i--;
			while (index < 4)
			{
				while (arr[i][j] == 1)
				{
					arr[i][j] = 6;
					j++;
				}
				j = y; i--;
				index++;
			}
		}
		if (length == 4)
		{
			j = y; i--;
			while (index < 9)
			{
				while (arr[i][j] == 1)
				{
					arr[i][j] = 6;
					j++;
				}
				j = y; i--;
				index++;
			}
		}
	}

	void change2(int x, int y)//当车位状态变为占用时进行改值
	{
		int i = x;
		int j = y;
		int length = 0;
		int index = 1;
		while (arr[i][j] == 6)
		{
			arr[i][j] = 7;
			j++;
		}
		length = j - y;
		if (length == 9)
		{
			j = y; i--;
			while (index < 4)
			{
				while (arr[i][j] == 6)
				{
					arr[i][j] = 7;
					j++;
				}
				j = y; i--;
				index++;
			}
		}
		if (length == 4)
		{
			j = y; i--;
			while (index < 9)
			{
				while (arr[i][j] == 6)
				{
					arr[i][j] = 7;
					j++;
				}
				j = y; i--;
				index++;
			}
		}
	}

private:
	int index;//编号
	int eleNum;//电量总数
};

class Manage//管理员类 
{
public:
	void initParking()//初始化停车场环境
	{
		build.model(arr);
	}
	void show()//展示停车场环境
	{

		build.print(arr);
	}
	void findParkingSpaceStatus()//查询车位状态
	{
		int x; int y;
		int index = 0;
		int free = 0;
		int busy = 0;

		FILE* fp1;
		fp1 = fopen("车位.txt", "r");

		multimap<int, int> mfree1;
		multimap<int, int> mbusy1;
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] == 1)
			{
				free++;
				mfree1.insert(make_pair(x, y));
			}				
		}
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] != 1)
			{
				busy++;
				mbusy1.insert(make_pair(x, y));
			}
		}
		fclose(fp1);
		cout << "空闲车位有:" << free << "个" << endl;
		if (free > 0){
			cout << "空闲车位左下角坐标为:" << endl;
			for (auto& e : mfree1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		cout << "非空闲车位有:" << busy << "个" << endl;
		if (busy > 0){
			cout << "已占用车位左下角坐标为:" << endl;
			for (auto& e : mbusy1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
		}		
	}
	void findRoadStatus()//查询便道状态
	{
		int x; int y;
		int index = 0;
		int free = 0;
		int busy = 0;

		FILE* fp1;
		fp1 = fopen("便道.txt", "r");

		multimap<int, int> mfree1;
		multimap<int, int> mbusy1;
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] == 2)
			{
				free++;
				mfree1.insert(make_pair(x, y));
			}
		}

		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] != 2)
			{
				busy++;
				mbusy1.insert(make_pair(x, y));
			}
		}

		fclose(fp1);
		cout << "空闲便道有:" << free << "个" << endl;
		if (free > 0){
			cout << "空闲便道左下角坐标为:" << endl;
			for (auto& e : mfree1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		cout << "非空闲便道有:" << busy << "个" << endl;
		if (busy > 0){
			cout << "已占用便道左下角坐标为:" << endl;
			for (auto& e : mbusy1)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
		}
	}
	int findAgvCarStatus()
	{
		int x; int y;
		int index = 0;
		int ele = 0;
		int rest = 0;

		FILE* fp1;
		fp1 = fopen("充电区.txt", "r");

		multimap<int, int> ele_m;
		multimap<int, int> rest_m;
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] == 3)
			{
				ele++;
				ele_m.insert(make_pair(x, y));
			}
		}
		fclose(fp1);
		cout << "小车总数为:" << AgvCarNum << endl;	
		if (ele > 0){
			cout << "充电小车有:" << ele << "个" << endl;
			cout << "充电小车左下坐标为:" << endl;
			for (auto& e : ele_m)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		FILE* fp2;
		fp2 = fopen("小车停靠区.txt", "r");
		while (1)
		{
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			if (arr[x][y] == 4)
			{
				rest++;
				rest_m.insert(make_pair(x, y));
			}
		}
		fclose(fp2);
		
		if (rest > 0){
			cout << "无任务停靠小车有:" << rest << "个" << endl;
			cout << "无任务停靠小车左下坐标为:" << endl;
			for (auto& e : rest_m)
				cout << "x:" << e.first << "--->" << "y:" << e.second << endl;
			cout << endl;
		}
		int ret = rest + ele;
		if (ret < AgvCarNum)
		{
			cout << "工作中的小车有" << AgvCarNum - ret<< "个" << endl;
		}
		return ret;
	}
private:
	Build build;
};

#endif