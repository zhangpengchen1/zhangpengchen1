#include "jinli.h"
jl::jl(string name, string age, string id, string leibie, string renwu)
{
	this->name = name;
	this->age = age;
	this->id = id;
	this->leibie = leibie;
	this->renwu = renwu;
}
void jl::xsxx()
{
	cout << "Ա������" << this->name
		<< "\tԱ������" << this->age
		<< "\tԱ�����" << this->id
		<< "\tԱ�����" << this->leibie
		<< "\tԱ������" << this->renwu << endl;
}