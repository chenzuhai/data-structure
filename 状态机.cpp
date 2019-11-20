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
	_ASSERT(ifs.good());//ʧ���򱨴�

	bool findB = false;
	bool findA = false;
	bool isKey = true;//��ǰ�ҵ��Ǽ�
	bool isValue = false;//����������ֵ(����)
	bool findEqu = false;

	bool findNode = false;//���ּ����е�Ԫ��

	bool findIdentifier = false;


	int layer = 0;//��¼����{{}}...���أ�=��ֻ��Ҫȡ��һ��Ϳ�����
	int startIndex = -1;//�涨��ʼλ��Ϊĳ��ʶ���ճ���ʱ��λ��
	int endIndex = -1;//����λ��Ϊ��ʶ�����һλ�ĺ���һλ


	getline(ifs, tmp);

	int pos = 0;
	char * str = (char*)tmp.c_str();
	int length = tmp.size();
	//example:A={1,2,3},B={a,b,c}
	for (int i = 0; i < length; i++)//��������б���
	{
		if (str[i] == '=')//���ֵȺ�֮��
		{
			findEqu = true;
			if (isKey)
			{
				isKey = false;
				isValue = true;
			}
			else if (isValue)//ֵ���治Ӧ���ǵȺ�
			{
				_ASSERT(false);//����
			}
			isKey = false;//���Ѿ�ȷ����
			isValue = true;//������ȷ��ֵ
		}
		else if (str[i] == '{')
		{
			if (layer > 0 && !findNode)//���֮ǰ�Ѿ���һ���˲���û����Ԫ�أ���ô��������{����Ԫ�ص�һ���ִ���
			{
				findNode = true;
				startIndex = i;
			}
			layer++;
		}
		else if (str[i] == '}')
		{
			layer--;
			if (layer < 0)//}���˵�Ȼ�ǲ��е�
			{
				_ASSERT(false);
			}
			if (layer == 0)//���԰�ĳ����ֵ�Եļ������һ��ȡ������
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
		else if (isIdentifier(str[i]))//��������˱�ʶ�������Ǽ��Ļ����Բ���
		{
			if (isValue)//����ֵ�����ϣ�
			{
				if (layer < 1)//�����Ǽ���
				{
					_ASSERT(false);
				}
				else if (layer == 1)
				{
					if (!findNode)//���û���ֽ��������Ϊ���ֲ�ȷ��Ϊ��ʼλ��
					{
						findNode = true;
						startIndex = i;
					}
				}
			}
		}
		else if (str[i] == ' ')//�ո������
		{

		}
		else if (str[i] == ',')
		{
			if (layer == 0)//���������Ķ���˵��ǰһ�������ˣ��ѳ��˷����б����������״̬����
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
				findNode = false;//���ּ����е�Ԫ��
				findIdentifier = false;

			}
			else//�������Ԫ�صĽ���
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
		else//���������ֵķ���ֱ�ӱ���
		{
			_ASSERT(false);
		}
	}
	if (layer != 0)//δ���
	{
		_ASSERT(false);
	}
}

int main(void)
{
	list<string> a, b;
	ReadAB(&a, &b, "test.txt");//���ļ�test.txt�ж�ȡ����a,b�б�
	for (list<string>::const_iterator it = a.begin(); it != a.end(); it++)//�����б�A
	{
		cout << *it << endl;
	}
	for (list<string>::const_iterator it = b.begin(); it != b.end(); it++)//�����б�B
	{
		cout << *it << endl;
	}
	_getch();//�ȴ���������
	return 0;
}
