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
	cout << "��ӭʹ��ѧ������ϵͳ" << endl;
	cout << "����������(����Ϊ1,���Ҫ�޸����룬ֱ����Դ�����޸�mima��ֵ)��";
	while (1)
	{
		cin >> rq;
		if (rq == mima)
		{
			cout << "������ȷ" << endl;
			break;
		}
		else
		{
			cout << "�����������������";
		}
	}
	system("pause");
	system("cls");
	while (true)
	{
		a.jiemian();
		cout << "��ѡ�����:";
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
			cout << "ѡ�����������ѡ��" << endl;
			break;
		}
	}
	return 0;
}