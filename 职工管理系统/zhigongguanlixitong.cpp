#include<iostream>
#include "shixiannei.h"
#include "zhigongnei.h"
#include "yuangong.h"
#include "jinli.h"
#include "boss.h"
using namespace std;
int main()
{

	gl a;
	int b = 0;
	int mima = 1;
	int rq;
	cout << "欢迎使用学生管理系统" << endl;
	cout << "请输入密码(密码为1,如果要修改密码，直接在源码中修改mima的值)：";
	while (1)
	{
		cin >> rq;
		if (rq == mima)
		{
			cout << "密码正确" << endl;
			break;
		}
		else
		{
			cout << "密码错误，请重新输入";
		}
	}
	system("pause");
	system("cls");
	while (true)
	{
		a.jiemian();
		cout << "请选择操作:";
		cin >> b;
		switch (b)
		{
		case 0:
			a.tuichu();
			break;
		case 1:
			a.tianjia();
			break;
		case 2:
			a.xszg();
			break;
		case 3:
			a.sczg();
			break;
		case 4:
			a.xgzg();
			break;
		case 5:
			a.czzgxi();
			break;
		case 6:
			a.paixu();
			break;
		case 7:
			a.qkwd();
			break;
		default:
			cout << "选择错误，请重新选择" << endl;
			break;
		}
	}
	return 0;
}