#include "boss.h"
boss::boss(string name, string age, string id, string leibie, string renwu)
{
	this->name = name;
	this->age = age;
	this->id = id;
	this->leibie = leibie;
	this->renwu = renwu;
}
void boss::xsxx()
{
	cout << "员工姓名" << this->name
		<< "\t员工年龄" << this->age
		<< "\t员工编号" << this->id
		<< "\t员工类别" << this->leibie
		<< "\t员工任务" << this->renwu << endl;
}