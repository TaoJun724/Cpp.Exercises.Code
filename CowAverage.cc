#include<iostream>
#include<algorithm>
using namespace std;
int a[100];


int main()
{
	int n;
	int sum = 0;
	int flag = 0;
	while (scanf("%d", &n)>0)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum = sum + a[i];
		}
		if (sum%n != 0)
			flag = 1;
		int avg = sum / n, count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (abs(a[i] - avg) % 2 != 0)
				flag = 1;
			count += abs(a[i] - avg) / 2;
		}
		if (flag)
			cout << -1 << endl;
		else
			cout << count / 2 << endl;
	}
}
