#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include<string.h>
using namespace  std;
class Thisinh
{
	private:
		char Maso[12];
		char Hoten[40];
		float Diemlt,Diemth,Dtb;
		char Ketqua[12];
	public:
		Thisinh();
		void Nhap();
		void Xuat();
		void TinhDTB();
		void Xeploai_cacts();
		float getDtb;
		float getDiemlt;
		float getDiemth;
};

class MangThisinh
{
	private:
		Thisinh mts[100];
		int n;
	public:
		void Nhap();
		void Tinh_DTB();
		void Xuat();
		void Xeploai_cacts();
};

int main()
{
	MangThisinh mThisinh;
	
	cout<<"nhap thong tin cac thi sinh :";
	mThisinh.Nhap();
	mThisinh.Tinh_DTB();
	mThisinh.Xeploai_cacts();
	
	cout<<"Thong tin cac thi sinh";
	mThisinh.Xuat();
	mThisinh.Tinh_DTB();
	
	getch();
	return 1;
}

// cac phuong thuc cua thi sinh
Thisinh::Thisinh()
{
	strcpy(Maso,"");
	strcpy(Hoten,"");
	Diemlt=Diemth=Dtb=0;
	
}

void Thisinh::Nhap()
{
	cout<<"Ma so thi sinh :"; gets(Maso);
	cout<<"ho ten thi sinh :"; gets(Hoten);
	cout<<"Diem ly thuyet thi sinh :";cin>>Diemlt;
	cout<<"Diem thuc hanh :"; cin>>Diemth;
	cin.ignore();
	
}

void Thisinh::Xuat()
{
	cout<<"==>\n Ma so :"<<Maso;
	cout<<"==>\n ho ten :"<<Hoten; 
	cout<<"==>\n Diem ly thuyet"<<Diemlt;
	cout<<"==>\n Diem thuc hanh"<<Diemth;
	cout<<"==>\n Diem TB"<<Dtb;
	cout<<"==>\n Xep loai"<<Ketqua;
}

void Thisinh::TinhDTB()
{
	Dtb=(Diemlt+Diemth*2)/3;
}
void Thisinh::Xeploai_cacts()
{
	if (Dtb>=5)
		strcpy(Ketqua,"Dat");
	else 
		strcpy(Ketqua,"Khong Dat");
}

// Cac phuong thuc cua mang thi sinh

void MangThisinh::Nhap()
{
	cout <<"\n So luong thi sinh :";cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cout<<" Nhap Thi sinh thu "<<i<<":"<<endl;
		mts[i].Nhap();
	}	
}
float getDiemlt;
float getDiemth;
float Dtb;

void MangThisinh::Xuat()
{
	for (int i=0;i<n;i++)
	{
		mts[i].Xuat();
		cout<<" ";
	}
	
}

void MangThisinh::Tinh_DTB()
{
	for (int i=0;i<n;i++)
	{
		mts[i].TinhDTB();
	}
	
}

void MangThisinh::Xeploai_cacts()
{

	for (int i=0;i<n;i++)
	{
		mts[i].Xeploai_cacts();
	}
	
}

