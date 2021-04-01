//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>

using namespace  std;

class GiaoDich
{	protected:
		char MaGD[20];
		int NgayGD;
		float Thanhtien;
	public:
		GiaoDich();
		virtual void Nhap();
		virtual void Xuat();
		virtual void Tinhthanhtien()=0;
		int getNgayGD();
		float getThanhtien();
};

class Vang: public GiaoDich
{	private:
		int Soluong;
		float Dongia;
		char Loaivang[10];
	public:
		Vang();
		void Nhap();
		void Xuat();
		void Tinhthanhtien();
};

class Tien: public GiaoDich
{	private:
		float Tygia;
		float Sotien;
		char Loaitien[10];
	public:
		Tien();
		void Nhap();
		void Xuat();
		void Tinhthanhtien();
};

int main()
{
	GiaoDich *gd[100];
	int n=0, dem=0;
	char Chon,Loai;
	cout<<"Nhap Cac Giao Dich";
	do
	{	cout<<"\nVang hay Tien (V/T)? ";
		cin>>Loai; 
		Loai=toupper(Loai);//in hoa Loai
		if (Loai=='V')
		{
			gd[n]=new Vang;
			gd[n]->Nhap();
			dem++;
		}
		else
		{	
			gd[n]=new Tien;
			gd[n]->Nhap();
		}
		n++;
		cout<<"Tiep tuc (C/K)? ";	cin>>Chon;
		Chon=toupper(Chon);
		if ((n==100) || (Chon=='K'))
			break;
	}
	while (1);
	
	cout<<"\nThong Tin Cac Giao Dich Vua Nhap";
	for(int i=0; i<n; i++)
	{
		gd[i]->Tinhthanhtien();
		gd[i]->Xuat();
		cout<<"\n-----------------------------\n";
	}

	int ngaybd=0, ngaykt=0;
	float tong=0;
	cout<<"\nNhap ngay bat dau: ";	cin>>ngaybd;
	cout<<"Nhap ngay ket thuc: ";	cin>>ngaykt;
	for(int i=0; i<n; i++)
		if((gd[i]->getNgayGD() > ngaybd) && (gd[i]->getNgayGD() < ngaykt))
			tong+=gd[i]->getThanhtien();
	cout<<"\nTBC thanh tien cua Vang trong so ngay vua nhap: "<<tong/(dem-1);
			
	getch();
	return 1;
}

//Cac phuong thuc class GiaoDich
GiaoDich::GiaoDich()
{
	strcpy(MaGD, " ");
	NgayGD=Thanhtien=0;
}

int GiaoDich::getNgayGD()
{
	return NgayGD;	
}

float GiaoDich::getThanhtien()
{
	return Thanhtien;
}

void GiaoDich::Nhap()
{
	cout<<"Ma GD: ";	cin.ignore();	gets(MaGD);
	do
	{
		cout<<"Ngay GD: ";
		cin>>NgayGD;
	}while( (NgayGD<1) || (NgayGD>31));
}

void GiaoDich::Xuat()
{
	cout<<"\nMa GD: "<<MaGD;
	cout<<", Ngay GD: "<<NgayGD;
	cout<<", Thanh tien: "<<Thanhtien;
}

//Cac phuong thuc class Vang
Vang::Vang()
{
	Soluong=Dongia=0;
	strcpy(Loaivang, " ");
}

void Vang::Nhap()
{
	GiaoDich::Nhap();
	cout<<"So luong: ";		cin>>Soluong;
	cout<<"Loai vang: ";	cin.ignore();	gets(Loaivang);
}

void Vang::Xuat()
{
	GiaoDich::Xuat();
	cout<<", So luong: "<<Soluong;
	cout<<", Don gia: "<<Dongia;
	cout<<", Loai vang: "<<Loaivang;
}

void Vang::Tinhthanhtien()
{
	if(stricmp(Loaivang, "SJC")==0 || stricmp(Loaivang, "PNJ")==0)
		Dongia=5400000;
	else
		Dongia=4800000;
	Thanhtien= Soluong*Dongia;
}

//Cac phuong thuc class Tien
Tien::Tien()
{
	Tygia=Sotien=0;
	strcpy(Loaitien, " ");
}

void Tien::Nhap()
{
	GiaoDich::Nhap();
	cout<<"So tien: ";		cin>>Sotien;
	cout<<"Loai tien: ";	cin.ignore();	gets(Loaitien);
}

void Tien::Xuat()
{
	GiaoDich::Xuat();
	cout<<", So tien: "<<Sotien;
	cout<<", Ty gia: "<<Tygia;
	cout<<", Loai tien: "<<Loaitien;
}

void Tien::Tinhthanhtien()
{
	if(stricmp(Loaitien, "VND")==0)
		Thanhtien=Sotien;
	else
	{
		if(stricmp(Loaitien, "USD")==0)
			Tygia=23000;
		else
			Tygia=27000;
		Thanhtien=Sotien*Tygia;
	}
}























