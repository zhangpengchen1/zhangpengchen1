#include "shixiannei.h"
#include <fstream>
#define WJ "ha.txt"//数据文件
gl::gl()
{
	ifstream ifs;
	ifs.open(WJ, ios::in);//读文件
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->rs = 0;
		this->zhigong = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->rs = 0;
		this->zhigong = NULL;
	}
	
	int renshuab = this->tjrs();
	//cout << "人数是" << renshuab << endl;
	this->rs = renshuab;
	this->zhigong = new zg *[renshuab];
	this->csh();
	/*for (int j = 0; j < this->rs; j++)
	{
		cout << "职工姓名" << this->zhigong[j]->name << " "
			<<"职工年龄" << this->zhigong[j]->age<< " "
			<< "职工编号" << this->zhigong[j]->id << " "
			<< "职工类型" << this->zhigong[j]->leibie<< " "
			<< "职工任务" << this->zhigong[j]->renwu << " " << endl;
	}*/
}
void gl::csh()//初始化数据
{
	ifstream ifs;
	ifs.open(WJ, ios::in);
	string name;//姓名
	string age;//年龄
	string id;//编号
	string leibie;//类别
	string renwu;//任务
	int ipx = 0;
	zg* p = NULL;
	while (ifs >> name && ifs >> age && ifs >> id && ifs >> leibie && ifs >> renwu)
	{
		if (leibie == "员工")
		{
			p = new yg(name, age, id, leibie, renwu);
		}
		else if(leibie == "经理")
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
	cout << "************欢迎使用职工管理系统*********************" << endl;
	cout << "************0 退出管理系统***************************" << endl;
	cout << "************1 增加职工信息***************************" << endl;
	cout << "************2 显示职工信息***************************" << endl;
	cout << "************3 删除职工信息***************************" << endl;
	cout << "************4 修改职工信息***************************" << endl;
	cout << "************5 查找职工信息***************************" << endl;
	cout << "************6 按照编号排序***************************" << endl;
	cout << "************7 清除文档*******************************" << endl;
}
void gl::tuichu()//退出
{
	exit(0);
}
int gl::tjrs()//统计人数
{
	ifstream ifs;
	ifs.open(WJ, ios::in);
	string name;//姓名
	string age;//年龄
	string id;//编号
	string leibie;//类别
	string renwu;//任务
	int num = 0;
	while(ifs >> name && ifs >> age && ifs >> id && ifs >> leibie && ifs >> renwu)
	{
		num++;
	}
	return num;
}
void gl::tianjia()//添加职工
{
	cout << "请输入添加职工的人数" << endl;
	int ren = 0;
	int p = 0;
	cin >> ren;
	string name;//姓名
	string age;//年龄
	string id;//编号
	string leibie;//类别
	string renwu;//任务
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
			cout << "请输入第" << j + 1 << "个人的姓名" << endl;
			cin >> name;
			cout << "请输入第" << j + 1 << "个人的年龄" << endl;
			cin >> age;
			cout << "请输入第" << j + 1 << "个人的编号" << endl;
			cin >> id;
			cout << "请输入第" << j + 1 << "个人的任务" << endl;
			cin >> renwu;
			cout << "请选择第" << j + 1 << "个人的类别" << endl;
			cout << "****1 员工" << endl;
			cout << "****2 经理" << endl;
			cout << "****3 老板" << endl;
			zg* ppp = NULL;
			int x = 1;
			while (x)
			{
				cin >> p;
				switch (p)
				{
				case 1:
					leibie = "员工";
					//string name, int age, string id, string leibie, string renwu
					ppp = new yg(name, age, id, leibie, renwu);
					x = 0;
					break;
				case 2:
					leibie = "经理";
					ppp = new jl(name, age, id, leibie, renwu);
					x = 0;
					break;
				case 3:
					leibie = "老板";
					ppp = new boss(name, age, id, leibie, renwu);
					x = 0;
					break;
				default:
					cout << "选择错误,重新选择" << endl;
				}
				//break;
			}
			xkj[this->rs + j] = ppp;
		}
		delete[] this->zhigong;
		this->zhigong = xkj;
		this->rs = zrs;
		cout << "添加成功" << endl;
		this->bcwj();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入有误" << endl;
	}
}
void gl::bcwj()//保存文件
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
void gl::xszg()//显示职工
{
	if (this->rs==0)
	{
		cout << "没有员工无法显示"<<endl;
		system("pause");
		system("cls"); return;
		return;
	}
	for (int j = 0; j < this->rs; j++)
	{
		cout << "职工姓名" << this->zhigong[j]->name << " "
			<< "职工年龄" << this->zhigong[j]->age << " "
			<< "职工编号" << this->zhigong[j]->id << " "
			<< "职工类型" << this->zhigong[j]->leibie << " "
			<< "职工任务" << this->zhigong[j]->renwu << " " << endl;
	}
	/*system("pause");
	system("cls");*/
}
void gl::sczg()//删除职工
{
	if (this->rs == 0)
	{
		cout << "没有员工无法删除"<<endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入删除职工的编号" << endl;
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
				cout << "删除成功" << endl;
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
				cout << "删除成功" << endl;
				this->bcwj();
				system("pause");
				system("cls");
				return;
			}
		}
	}
	cout << "编号错误" << endl;
	system("pause");
	system("cls");
}
void gl::xgzg()//修改职工
{
	if (this->rs == 0)
	{
		cout << "没有员工无法修改"<<endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "输入修改职工的编号:";
	string a;
	int x = 0;
	string sj;
	int p = 0;
	cin >> a;
	for (int i = 0; i < this->rs; i++)
	{
		if (a == this->zhigong[i]->id)
		{
			cout << "***1 姓名***" << endl;
			cout << "***2 年龄***" << endl;
			cout << "***3 编号***" << endl;
			cout << "***4 任务***" << endl;
			cout << "***5 类别***" << endl;
			cout << "请选择修改的信息:";
			cin >> x;
			do
			{
				switch (x)
				{
				case 1:
					cout << "请输入修改后的姓名:";
					cin >> sj;
					this->zhigong[i]->name = sj;
					x = 0;
					break;
				case 2:
					cout << "请输入修改后的年龄:";
					cin >> sj;
					this->zhigong[i]->age= sj;
					x = 0;
					break;
				case 3:
					cout << "请输入修改后的编号:";
					cin >> sj;
					this->zhigong[i]->id = sj;
					x = 0;
					break;
				case 4:
					cout << "请输入修改后的任务:";
					cin >> sj;
					this->zhigong[i]->renwu = sj;
					x = 0;
					break;
				case 5:
					cout << "****1 员工" << endl;
					cout << "****2 经理" << endl;
					cout << "****3 老板" << endl;
					cout << "请输入修改的类别:";
					cin >> p;
					switch (p)
					{
					case 1:
						this->zhigong[i]->leibie = "员工";
						x = 0;
						break;
					case 2:
						x = 0;
						this->zhigong[i]->leibie = "经理";
						break;
					case 3:
						x = 0;
						this->zhigong[i]->leibie = "老板";
						break;
					default:
						cout << "选择错误"<<endl;
						system("pause");
						system("cls");
						return;
					}
					break;
				default:
					cout << "选择错误" << endl;
					system("pause");
					system("cls");
					return;
				}
			} while (x);
			this->bcwj();
			cout << "修改成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "没有找到输入的编号" << endl;
	system("pause");
	system("cls");
}
void gl ::czzgxi()//查找职工信息
{
	if (this->rs == 0)
	{
		cout << "没有员工无法查找"<<endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入查找的编号" << endl;
	string a;
	cin >> a;
	for (int i = 0; i < this->rs; i++)
	{
		if (a == this->zhigong[i]->id)
		{
			cout << "职工姓名" << this->zhigong[i]->name << " "
				<< "职工年龄" << this->zhigong[i]->age << " "
				<< "职工编号" << this->zhigong[i]->id << " "
				<< "职工类型" << this->zhigong[i]->leibie << " "
				<< "职工任务" << this->zhigong[i]->renwu << " " << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "没有找到" << endl;
	system("pause");
	system("cls");
}
void gl::paixu()//排序
{
	if (this->rs == 0)
	{
		cout << "没有员工无法排序"<<endl;
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
	cout << "排序完成" << endl;
	system("pause");
	system("cls");
}
void gl::qkwd()//清空文档
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
	cout << "清空完成" << endl;
	system("pause");
	system("cls");
}