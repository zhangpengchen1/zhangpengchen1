#include "yuangong.h"
yg::yg(string name, string age, string id, string leibie, string renwu)
{
	this->name = name;
	this->age = age;
	this->id =id;
	this->leibie = leibie;
	this->renwu = renwu;
}

void yg::xsxx()//��ʾԱ��
{
	cout << "Ա������" << this->name
		<< "\tԱ������" << this->age
		<< "\tԱ�����" << this->id
		<< "\tԱ�����" << this->leibie
		<< "\tԱ������" << this->renwu << endl;
}