#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <conio.h>
using namespace std;

inline bool isIdentifier(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
}

void ReadAB(list<string> *a, list<string> *b, const string & inputFilePath)
{
	char split = ',';
	char eq = '=';
	ifstream ifs;
	string tmp;
	ifs.open(inputFilePath);
	_ASSERT(ifs.good());//失败则报错

	bool findB = false;
	bool findA = false;
	bool isKey = true;//当前找的是键
	bool isValue = false;//接下来再找值(集合)
	bool findEqu = false;

	bool findNode = false;//发现集合中的元素

	bool findIdentifier = false;


	int layer = 0;//记录层数{{}}...￣ω￣=，只需要取第一层就可以了
	int startIndex = -1;//规定开始位置为某标识符刚出现时的位置
	int endIndex = -1;//结束位置为标识符最后一位的后面一位


	getline(ifs, tmp);

	int pos = 0;
	char * str = (char*)tmp.c_str();
	int length = tmp.size();
	//example:A={1,2,3},B={a,b,c}
	for (int i = 0; i < length; i++)//对数组进行遍历
	{
		if (str[i] == '=')//发现等号之后
		{
			findEqu = true;
			if (isKey)
			{
				isKey = false;
				isValue = true;
			}
			else if (isValue)//值后面不应该是等号
			{
				_ASSERT(false);//报错
			}
			isKey = false;//键已经确定了
			isValue = true;//接下来确定值
		}
		else if (str[i] == '{')
		{
			if (layer > 0 && !findNode)//如果之前已经有一层了并且没发现元素，那么接下来的{当做元素的一部分处理
			{
				findNode = true;
				startIndex = i;
			}
			layer++;
		}
		else if (str[i] == '}')
		{
			layer--;
			if (layer < 0)//}多了当然是不行滴
			{
				_ASSERT(false);
			}
			if (layer == 0)//可以把某个键值对的集合最后一个取出来了
			{
				endIndex = i;
				findNode = false;

				string t = tmp.substr(startIndex, endIndex - startIndex);
				if (!findA)
				{
					a->push_back(t);
				}
				else
				{
					a->push_back(t);
				}
			}
		}
		else if (isIdentifier(str[i]))//如果发现了标识符并且是键的话可以不管
		{
			if (isValue)//代表值（集合）
			{
				if (layer < 1)//必须是集合
				{
					_ASSERT(false);
				}
				else if (layer == 1)
				{
					if (!findNode)//如果没发现结点则设置为发现并确定为起始位置
					{
						findNode = true;
						startIndex = i;
					}
				}
			}
		}
		else if (str[i] == ' ')//空格则忽略
		{

		}
		else if (str[i] == ',')
		{
			if (layer == 0)//如果是外面的逗号说明前一个结束了，把除了发现列表以外的所有状态重置
			{
				if (!findA)
				{
					findA = true;
				}
				else if (findA)
				{
					findB = true;
					return;
				}

				isKey = true;
				isValue = false;
				findEqu = false;
				findNode = false;//发现集合中的元素
				findIdentifier = false;

			}
			else//否则就是元素的结束
			{
				endIndex = i;
				findNode = false;
				string t = tmp.substr(startIndex, endIndex - startIndex);
				if (!findA)
				{
					a->push_back(t);
				}
				else
				{
					a->push_back(t);
				}
			}
		}
		else//如果混入奇怪的符号直接报错
		{
			_ASSERT(false);
		}
	}
	if (layer != 0)//未封闭
	{
		_ASSERT(false);
	}
}

int main(void)
{
	list<string> a, b;
	ReadAB(&a, &b, "test.txt");//从文件test.txt中读取放入a,b列表
	for (list<string>::const_iterator it = a.begin(); it != a.end(); it++)//遍历列表A
	{
		cout << *it << endl;
	}
	for (list<string>::const_iterator it = b.begin(); it != b.end(); it++)//遍历列表B
	{
		cout << *it << endl;
	}
	_getch();//等待任意输入
	return 0;
}
