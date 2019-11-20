#include<iostream>
#include<malloc.h>
using namespace std;
typedef char Element;  //取别名
/*  Node
* 功能储存栈里每个节点
*  data 储存数据
*  指向下上一个节点的指针
*/
typedef struct Node
{
	Element data;
	struct Node *next;
}LStackNode;
/* LStack
*  储存指向栈顶的指针
*  栈内节点个数
*/
typedef struct
{
	LStackNode *Top;
	int count;
}LStack;
/*void InitStack(LStack *S)
* 功能：初始化一个栈
* 输入：表头节点的指针
*/
void InitStack(LStack *S)
{
	S->Top = NULL; //将栈顶指针置为空
	S->count = 0;  //栈内元素为0
}
/*int StackEmpty(LStack *S)
* 功能: 判断链栈是否为空
* 输入: 表头节点的指针
* return 1 表示为空
* return 0 表示不为空
*/
int StackEmpty(LStack *S)
{
	if (S->Top == NULL)return 1;//如果栈顶指针为空，表明栈为空

	return 0;
}
/*int Push(LStack *S, Element Data)
* 功能：将元素进栈
* 输入：表头节点的指针 和 数据
* return 0  表示正常
* return -1 表示分配内存失败
*/
int Push(LStack *S, Element Data)
{
	LStackNode *p;
	p = (LStackNode*)malloc(sizeof(LStackNode));//分配内存
	if (!p)
	{
		cout << "分配内存失败" << endl;
		return -1;
	}
	p->data = Data;  //将值赋给这个节点
	p->next = S->Top;//这个节点指向之前的栈顶指针
	S->Top = p;      //将这个节点p作为新的栈顶节点
	S->count++;      //节点个数+1
	return 0;
}
/*int Pop(LStack *S, Element &data)
* 功能：将元素出栈并获得这个数据
* 输入：表头节点的指针 和 数据
* return 0  表示正常
* return -1 表示栈为空
*/
int Pop(LStack *S, Element &data)
{
	LStackNode *temp;         //新建一个中间变量保存栈顶节点
	temp = S->Top;
	if (StackEmpty(S) == 1)
	{
		cout << "栈为空,无法出栈" << endl;
		return -1;
	}
	data = temp->data;  //将这个即将被删除的节点的值保存
	S->Top = temp->next;//将栈顶指针置为上一个节点
	S->count--;         //节点个数-1
	free(temp);         //释放节点
	return 1;
}
/*int getCount(LStack *S)
* 功能: 获得栈内元素个数
* 返回值 为元素个数
*/
int getCount(LStack *S)
{
	return S->count;
}
/*int getTop(LStack *S, Element &e)
* 功能: 获取栈顶元素值
* return -1 表示栈为空
* return 0 表示正常
*/
int getTop(LStack *S, Element &e)
{
	if (StackEmpty(S) == 1)
	{
		cout << "栈为空" << endl;
		return -1;
	}
	e = S->Top->data;
	return 0;
}
/*int check(string expressing)
* 功能: 检查表达式的括号是否匹配
* 输入：string类型表达式
* 数据结构第四次作业第一题
*/
int check(string expr)
{
	LStack S;
	InitStack(&S);
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{'  )
		{
			Push(&S, expr[i]);
		}
		else if (expr[i] == '/')
		{
			Push(&S, expr[i]);
			if (expr[i + 1] != '*')
			{
				cout << "表达式错误" << endl;
				return -1;
			}
			else
			{
				Push(&S, expr[i+1]);
				i++;
			}
		}
		else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
		{
			char e;
			if (expr[i] == ')')
			{
				int flag;
				flag = Pop(&S, e);
				if (e != '(' || flag == -1)
				{
					cout << "表达式错误" << endl;
					return -1;
				}
				
			}
			else if (expr[i] == ']')
			{
				int flag;
				flag=Pop(&S, e);
				if (e != '['||flag==-1)
				{
					cout << "表达式错误" << endl;
					return -1;
				}

			}
			else if (expr[i] == '}')
			{
				int flag;
				flag = Pop(&S, e);
			
				if (e != '{' || flag == -1)
				{
					cout << "表达式错误" << endl;
					return -1;
				}

			}
		}
		else if (expr[i] == '*')
		{

			if (expr[i+1] != '/')
			{
				cout << "表达式错误" << endl;
				return -1;
			}
			else
			{
				int flag;
				char e, f;
				Pop(&S, e);
				flag=Pop(&S, f);
				if (e != '*' || f != '/' || flag == -1)
				{
					cout << "表达式错误" << endl;
					return -1;
				}
				i++;
			}
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == 'c' || expr[i] == '/'||(expr[i]>'0'&&expr[i]<'9'))
		{

		}
		else
		{
			cout << "奇怪符号混入" << endl;
			return -1;
		}
	}
	cout << "表达式正确" << endl;
	return 0;
}
int main()
{
	string a = "{[(3+40)6+5]}";
	check(a);
	return 0;
}