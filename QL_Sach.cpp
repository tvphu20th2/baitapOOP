#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

#define MAX_NXB		50
//Class Nhanvien
class QLSach
{	protected:
		char MaSach[12];
		char NgayNhap[12];
		float DonGia;
		int SoLuong;
		char NXB[50];
		float ThanhTien;
	public:
		QLSach();
		virtual void Nhap();
		void Xuat(); 
		virtual void TinhTien()=0; //Ham thuan ao
		//...bo sung code
};

	
//Class Bien che
class SachGK: public QLSach
{
	protected:
		int TinhTrang; //1-Moi; 0-Cu
	public:
		SachGK();
		void TinhTien();
		void Nhap();
		//...bo sung code
};

//Dinh nghia lop SachTK

class SachTK : public QLSach
{
	protected:
		float Thue; 
	public:
		SachTK();
		void Nhap();
		void TinhTien();
		//...bo sung code
};

//Dinh nghia ham thanh vien cho lop QLSach
QLSach::QLSach()
{
	strcpy(MaSach,"");
	strcpy(NgayNhap,"");
	strcpy(NXB,"");
	ThanhTien=DonGia=SoLuong=0;
}

void QLSach::Nhap()
{
	//bo sung code
}

void QLSach::Xuat() 
{
	cout<<"MS: "<<MaSach<<",NG: "<<NgayNhap;
	cout<<",DG: "<<DonGia<<",SL: "<<SoLuong;
	cout<<",TT: "<<ThanhTien<<"NXB: "<<NXB<<endl;
}


//Dinh nghia ham thanh vien cho lop SachGK
SachGK::SachGK(): QLSach() 
{
	//QLSach::QLSach();
	TinhTrang=1; //mac nhien la Sach moi
}
void SachGK::TinhTien()
{
	if (TinhTrang==1)
		ThanhTien=SoLuong*DonGia;
	else
		ThanhTien=SoLuong*DonGia*0.5;
}

void SachGK::Nhap()
{
	//...bo sung code
}

//Cac ham thanh vien trong lop SachTK
SachTK::SachTK(): QLSach() 
{
	Thue=0;
}

void SachTK::Nhap()
{
	//...bo sung code
}

void SachTK::TinhTien()
{
	ThanhTien= SoLuong*DonGia + Thue;
}

int main()
{
	QLSach *MSach[100];
	int i=0,n=0;
	char Chon,Loai, nxb_ct[50];
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Nhap thong tin cho cac loai sach"<<endl;
	do
	{
		cout<<"Sack Giao khoa hay Sach Tham khao (G/T)? ";
		cin>>Loai;
		Loai=toupper(Loai);
		if (Loai=='G')
			{
				//...bo sung code
			}
			
		else
			{
			//...bo sung code
			}
		n++; //tang len so luong sach
		cout<<"Tiep tuc (C/K)? ";
		cin>>Chon;
		Chon=toupper(Chon);
		if ((n==100)||(Chon=='K'))
			break;
	}
	while (1);
	
	//...bo sung code
			
	getch();
	return 1;
}

