#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

void DelectOneChar(char* str1, char str2)
{
	if (str1 == nullptr)
		return;
	int length = strlen(str1);
	char *p = str1;
	//遍历str,删除和str2相等的字符
	for (int i = 0; str1[i] != '\0'&& i < length; i++)
	{
		//如果相等则用后面的元素覆盖
		if (str1[i] == str2)
		{
			int j = i;
			for (; str1[j] != '\0'&&j < length - 1; j++)
				str1[j] = str1[j + 1];
			str1[j] = '\0';
		}
	}
	return;
}


//方法一时间复杂度：O（n^2)
void DelectChar1(char* str1, const char* str2)
{
	if (str1 == nullptr)
		return;
	if (str2 == nullptr)
		return;
	//依次删除chars中的每一个元素
	for (int i = 0; i < strlen(str2); i++)
		DelectOneChar(str1, str2[i]);
}

int main()
{
	char* str = "they are students";
	char* p = (char*)malloc((strlen(str) + 1)*sizeof(char));
	strcpy(p, str);
	const char*q = "aeiou";
	DelectChar1(p, q);
	cout << p << endl;
	free(p);
	p = NULL;
}
