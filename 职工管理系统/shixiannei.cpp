#include "shixiannei.h"
#include <fstream>
#define WJ "ha.txt"//�����ļ�
gl::gl()
{
	ifstream ifs;
	ifs.open(WJ, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->rs = 0;
		this->zhigong = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->rs = 0;
		this->zhigong = NULL;
	}
	
	int renshuab = this->tjrs();
	//cout << "������" << renshuab << endl;
	this->rs = renshuab;
	this->zhigong = new zg *[renshuab];
	this->csh();
	/*for (int j = 0; j < this->rs; j++)
	{
		cout << "ְ������" << this->zhigong[j]->name << " "
			<<"ְ������" << this->zhigong[j]->age<< " "
			<< "ְ�����" << this->zhigong[j]->id << " "
			<< "ְ������" << this->zhigong[j]->leibie<< " "
			<< "ְ������" << this->zhigong[j]->renwu << " " << endl;
	}*/
}
void gl::csh()//��ʼ������
{
	ifstream ifs;
	ifs.open(WJ, ios::in);
	string name;//����
	string age;//����
	string id;//���
	string leibie;//���
	string renwu;//����
	int ipx = 0;
	zg* p = NULL;
	while (ifs >> name && ifs >> age && ifs >> id && ifs >> leibie && ifs >> renwu)
	{
		if (leibie == "Ա��")
		{
			p = new yg(name, age, id, leibie, renwu);
		}
		else if(leibie == "����")
		{
			p = new jl(name, age, id, leibie, renwu);
		}
		else
		{
			p = new boss(name, age, id, leibie, renwu);
		}
		this->zhigong[ipx] = p;
		ipx++;
	}
	ifs.close();
}
void gl::jiemian()
{
	cout << "************��ӭʹ��ְ������ϵͳ*********************" << endl;
	cout << "************0 �˳�����ϵͳ***************************" << endl;
	cout << "************1 ����ְ����Ϣ***************************" << endl;
	cout << "************2 ��ʾְ����Ϣ***************************" << endl;
	cout << "************3 ɾ��ְ����Ϣ***************************" << endl;
	cout << "************4 �޸�ְ����Ϣ***************************" << endl;
	cout << "************5 ����ְ����Ϣ***************************" << endl;
	cout << "************6 ���ձ������***************************" << endl;
	cout << "************7 ����ĵ�*******************************" << endl;
}
void gl::tuichu()//�˳�
{
	exit(0);
}
int gl::tjrs()//ͳ������
{
	ifstream ifs;
	ifs.open(WJ, ios::in);
	string name;//����
	string age;//����
	string id;//���
	string leibie;//���
	string renwu;//����
	int num = 0;
	while(ifs >> name && ifs >> age && ifs >> id && ifs >> leibie && ifs >> renwu)
	{
		num++;
	}
	return num;
}
void gl::tianjia()//���ְ��
{
	cout << "���������ְ��������" << endl;
	int ren = 0;
	int p = 0;
	cin >> ren;
	string name;//����
	string age;//����
	string id;//���
	string leibie;//���
	string renwu;//����
	int zrs = this->rs + ren;
	zg** xkj = new zg * [zrs];
	if (this->zhigong != NULL)
	{
		for (int i = 0; i < this->rs; i++)
		{
			xkj[i] = this->zhigong[i];
		}
	}
	if (ren > 0)
	{
		for(int j=0;j<ren;j++)
		{
			cout << "�������" << j + 1 << "���˵�����" << endl;
			cin >> name;
			cout << "�������" << j + 1 << "���˵�����" << endl;
			cin >> age;
			cout << "�������" << j + 1 << "���˵ı��" << endl;
			cin >> id;
			cout << "�������" << j + 1 << "���˵�����" << endl;
			cin >> renwu;
			cout << "��ѡ���" << j + 1 << "���˵����" << endl;
			cout << "****1 Ա��" << endl;
			cout << "****2 ����" << endl;
			cout << "****3 �ϰ�" << endl;
			zg* ppp = NULL;
			int x = 1;
			while (x)
			{
				cin >> p;
				switch (p)
				{
				case 1:
					leibie = "Ա��";
					//string name, int age, string id, string leibie, string renwu
					ppp = new yg(name, age, id, leibie, renwu);
					x = 0;
					break;
				case 2:
					leibie = "����";
					ppp = new jl(name, age, id, leibie, renwu);
					x = 0;
					break;
				case 3:
					leibie = "�ϰ�";
					ppp = new boss(name, age, id, leibie, renwu);
					x = 0;
					break;
				default:
					cout << "ѡ�����,����ѡ��" << endl;
				}
				//break;
			}
			xkj[this->rs + j] = ppp;
		}
		delete[] this->zhigong;
		this->zhigong = xkj;
		this->rs = zrs;
		cout << "��ӳɹ�" << endl;
		this->bcwj();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������" << endl;
	}
}
void gl::bcwj()//�����ļ�
{
	ofstream ofs;
	ofs.open(WJ,ios::out);
	for (int i = 0; i < this->rs; i++)
	{
		ofs << this->zhigong[i]->name << " "
			<< this->zhigong[i]->age << " "
			<< this->zhigong[i]->id << " "
			<< this->zhigong[i]->leibie << " "
			<< this->zhigong[i]->renwu << " " << endl;
	}
	ofs.close();

}
void gl::xszg()//��ʾְ��
{
	if (this->rs==0)
	{
		cout << "û��Ա���޷���ʾ"<<endl;
		system("pause");
		system("cls"); return;
		return;
	}
	for (int j = 0; j < this->rs; j++)
	{
		cout << "ְ������" << this->zhigong[j]->name << " "
			<< "ְ������" << this->zhigong[j]->age << " "
			<< "ְ�����" << this->zhigong[j]->id << " "
			<< "ְ������" << this->zhigong[j]->leibie << " "
			<< "ְ������" << this->zhigong[j]->renwu << " " << endl;
	}
	/*system("pause");
	system("cls");*/
}
void gl::sczg()//ɾ��ְ��
{
	if (this->rs == 0)
	{
		cout << "û��Ա���޷�ɾ��"<<endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "������ɾ��ְ���ı��" << endl;
	string a;
	cin >> a;
	for (int i = 0; i < this->rs; i++)
	{
		if (a == this->zhigong[i]->id)
		{
			int j = i;
			if (j == this->rs-1)
			{
			/*	delete[]this->zhigong[j];
				this->zhigong[j] = NULL;*/
				this->rs--;
				cout << "ɾ���ɹ�" << endl;
				this->bcwj();
				system("pause");
				system("cls");
				return;
			}
			else
			{
				for (int p = j; p < this->rs; p++)
				{
					this->zhigong[p] = this->zhigong[p + 1];
				}
				this->rs--;
				cout << "ɾ���ɹ�" << endl;
				this->bcwj();
				system("pause");
				system("cls");
				return;
			}
		}
	}
	cout << "��Ŵ���" << endl;
	system("pause");
	system("cls");
}
void gl::xgzg()//�޸�ְ��
{
	if (this->rs == 0)
	{
		cout << "û��Ա���޷��޸�"<<endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�����޸�ְ���ı��:";
	string a;
	int x = 0;
	string sj;
	int p = 0;
	cin >> a;
	for (int i = 0; i < this->rs; i++)
	{
		if (a == this->zhigong[i]->id)
		{
			cout << "***1 ����***" << endl;
			cout << "***2 ����***" << endl;
			cout << "***3 ���***" << endl;
			cout << "***4 ����***" << endl;
			cout << "***5 ���***" << endl;
			cout << "��ѡ���޸ĵ���Ϣ:";
			cin >> x;
			do
			{
				switch (x)
				{
				case 1:
					cout << "�������޸ĺ������:";
					cin >> sj;
					this->zhigong[i]->name = sj;
					x = 0;
					break;
				case 2:
					cout << "�������޸ĺ������:";
					cin >> sj;
					this->zhigong[i]->age= sj;
					x = 0;
					break;
				case 3:
					cout << "�������޸ĺ�ı��:";
					cin >> sj;
					this->zhigong[i]->id = sj;
					x = 0;
					break;
				case 4:
					cout << "�������޸ĺ������:";
					cin >> sj;
					this->zhigong[i]->renwu = sj;
					x = 0;
					break;
				case 5:
					cout << "****1 Ա��" << endl;
					cout << "****2 ����" << endl;
					cout << "****3 �ϰ�" << endl;
					cout << "�������޸ĵ����:";
					cin >> p;
					switch (p)
					{
					case 1:
						this->zhigong[i]->leibie = "Ա��";
						x = 0;
						break;
					case 2:
						x = 0;
						this->zhigong[i]->leibie = "����";
						break;
					case 3:
						x = 0;
						this->zhigong[i]->leibie = "�ϰ�";
						break;
					default:
						cout << "ѡ�����"<<endl;
						system("pause");
						system("cls");
						return;
					}
					break;
				default:
					cout << "ѡ�����" << endl;
					system("pause");
					system("cls");
					return;
				}
			} while (x);
			this->bcwj();
			cout << "�޸ĳɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "û���ҵ�����ı��" << endl;
	system("pause");
	system("cls");
}
void gl ::czzgxi()//����ְ����Ϣ
{
	if (this->rs == 0)
	{
		cout << "û��Ա���޷�����"<<endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������ҵı��" << endl;
	string a;
	cin >> a;
	for (int i = 0; i < this->rs; i++)
	{
		if (a == this->zhigong[i]->id)
		{
			cout << "ְ������" << this->zhigong[i]->name << " "
				<< "ְ������" << this->zhigong[i]->age << " "
				<< "ְ�����" << this->zhigong[i]->id << " "
				<< "ְ������" << this->zhigong[i]->leibie << " "
				<< "ְ������" << this->zhigong[i]->renwu << " " << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "û���ҵ�" << endl;
	system("pause");
	system("cls");
}
void gl::paixu()//����
{
	if (this->rs == 0)
	{
		cout << "û��Ա���޷�����"<<endl;
		system("pause");
		system("cls");
	}
	for (int i = 0; i < this->rs; i++)
	{
		for (int j = 0 ;j <this->rs-i-1;j++)
		{
			if (this->zhigong[j]->id > this->zhigong[j + 1]->id)
			{
				zg* a;
				a = this->zhigong[j];
				this->zhigong[j]= this->zhigong[j+1];
				this->zhigong[j + 1] = a;
			}
		}
	}
	cout << "�������" << endl;
	system("pause");
	system("cls");
}
void gl::qkwd()//����ĵ�
{
	ofstream ofs;
	ofs.open(WJ, ios::trunc);
	ofs.close();
	for (int i = 0; i < this->rs; i++)
	{
		delete this->zhigong[i];
		this->zhigong[i] = NULL;
	}
	delete[]this->zhigong;
	this->zhigong = NULL;
	this->rs = 0;
	cout << "������" << endl;
	system("pause");
	system("cls");
}