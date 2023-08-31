#pragma once
#include <iostream>
#include <string>
using namespace std;
class zg//职工，不同的职工的父类
{
public:
	virtual void xsxx() = 0;//显示信息
	string name;//姓名
	string age;//年龄
	string id;//编号
	string leibie;//类别
	string renwu;//任务
};