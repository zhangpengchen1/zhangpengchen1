#pragma once
#include<iostream>
#include "zhigongnei.h"
#include "yuangong.h"
#include "jinli.h"
#include "boss.h"
using namespace std;
class gl//管理类
{
public:
	gl();
	void jiemian();//界面图像
	void tuichu();//退出函数
	zg** zhigong;
	int rs;//人数
	void tianjia();//添加职工
	int tjrs();//统计人数
	void bcwj();//保存文件
	void csh();//初始化数据
	void xszg();//显示职工
	void sczg();//删除职工
	void xgzg();//修改职工
	void czzgxi();//查找职工信息
	void paixu();//排序
	void qkwd();//清空文档
};