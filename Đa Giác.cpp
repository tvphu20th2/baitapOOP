//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <iostream>
using namespace  std;
class Dagiac
{
	protected :
		float dt;
		float cv;
	public :
		virtual void Nhap()=0;
		virtual void Xuat()=0;
		virtual void TinhCV()=0;
		virtual void TinhDT()=0;
		float getCV;
		float getDT;
};
//Class Hinh chu nhat
class HinhCN::public Dagiac
{
	private:
		float dai;
		float rong;  
	public:
		HinhCN();
		HinhCN(float d, float r);
		void Nhap();
		void Xuat();
		void TinhDT();
		void TinhCV();
		float getCV();
		float getDT();
		float getDai();
		float getRong();
		//..cac phuong thuc khac
};


//Hinh vuong
class HinhVuong:public Dagiac
{
	private: 
		float canh;
		//ke thua dt, cv Dagiac

	public:
		HinhVuong();
		HinhVuong(float c);
		void Nhap();
		void Xuat();
		void TinhDT();
		void TinhCV();
		//float getCV();
		//float getDT();
		float getCanh();
};

int main()
{
	Dagiac *pdg;
	HinhCN	hcn[50];
	HinhVuong hv[50];
	
	cout<<"\n Nhap Thong Tin Hinh Chu Nhat :  "<<endl;
	pdg=&hcn;
	pdg->Nhap();
	pdg->Xuat();
	pdg->TinhCV();
	pdg->TinhDT();
	
	cout<<"\n Nhap Thong Tin Hinh Vuong :  "<<endl;
	pdg=&hv;
	pdg->Nhap();
	pdg->Xuat();
	pdg->TinhCV();
	pdg->TinhDT();
	int n,m;
	cout<<"So luong Hinh CN: "; cin>>n;
	for(int i=0; i<n;i++)
		hcn[i].Nhap();
		
	cout<<"Thong tin cac  Hinh CN: "<<endl;
	for(int i=0; i<n;i++)
		hcn[i].Xuat();
	
	//..Them code
	hcn[i].TinhCV();
	hcn[i].TinhDT();
	
	getch();
	return 1;
}
Dagiac::Dagiac()
{
	dt=cv=0;
}
float Dagiac::getCV()
{
	return cv;
}
float Dagiac::getDT()
{
	return dt;
}
//Cac phuong thuc Hinh CN
HinhCN::HinhCN()
{
	dai = rong = dt=cv=0;
}
HinhCN::HinhCN(float d,float r)
{
	dai=d; rong=r;
}

void HinhCN::Nhap()
{
	float d,r;
	cout<<"nhap do dai canh dai: "; cin>>dai;
	cout<<"nhap do dai canh rong: "; cin>>rong;
	//..Them code
	if (d>r)
	{
		dai=d;  rong=r;
	}
	else
	{
		dai=r;  rong=d;
		
	}
}
void HinhCN::Xuat()
{
	cout<<"canh dai: "<<dai<<" canh rong: "<<rong;
	cout<<" Chu vi: "<<cv<<" Dien tich: "<<dt<<endl;
}

void HinhCN::TinhDT()
{
	dt=(dai*rong);
}

void HinhCN::TinhCV()
{
	cv= (dai+rong)*2;
}

float HinhCN::getDai()
{
	return dai;
}

float HinhCN::getRong()
{
	return rong;
}

float HinhCN::getCV()
{
	return cv;
}

float HinhCN::getDT()
{
	return dt;
}
//Cac phuong thuc cua Hinh Vuong



