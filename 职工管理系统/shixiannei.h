#pragma once
#include<iostream>
#include "zhigongnei.h"
#include "yuangong.h"
#include "jinli.h"
#include "boss.h"
using namespace std;
class gl//������
{
public:
	gl();
	void jiemian();//����ͼ��
	void tuichu();//�˳�����
	zg** zhigong;
	int rs;//����
	void tianjia();//���ְ��
	int tjrs();//ͳ������
	void bcwj();//�����ļ�
	void csh();//��ʼ������
	void xszg();//��ʾְ��
	void sczg();//ɾ��ְ��
	void xgzg();//�޸�ְ��
	void czzgxi();//����ְ����Ϣ
	void paixu();//����
	void qkwd();//����ĵ�
};