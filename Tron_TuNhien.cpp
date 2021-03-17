#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

void CreatFile(FILE *Ft,int);
void ListFile(FILE *);
void Distribute();
void Copy(FILE *,FILE *);
void CopyRun(FILE *,FILE *);
void MergeRun();
void Merge();

typedef int DataType;

FILE *F0,*F1,*F2;
int M,N,Eor;

DataType X1,X2,X,Y;

int main(void)
{
	cout<<"Nhap so phan tu: ";
	cin>>N;
	CreatFile(F0,N);
	ListFile(F0);
	do
	{
		F0=fopen("D:\\bang.txt","rb");
		F1=fopen("D:\\bang1.txt","wb");
		F2=fopen("D:\\bang2.txt","wb");
		Distribute();
		F0=fopen("D:\\bang.txt","wb");
		F1=fopen("D:\\bang1.txt","rb");
		F2=fopen("D:\\bang2.txt","rb");
		M=0;
		Merge();	
	}while (M !=1);
	ListFile(F0);
	getch();
	return 0;
}
void CreatFile(FILE *Ft,int Num)
{
Ft=fopen("D:\\bang.txt","wb");
for( int i=0;i<Num;i++)
{
    scanf("%d",&X);
    fprintf(Ft,"%3d",X);
}
    fclose(Ft);
}
void ListFile(FILE *Ft)
{
	DataType X,I=0;
	Ft=fopen("D:\\bang.txt","rb");
	while (I < N)
	{
		fscanf(Ft,"%3d",&X);
		cout<<" "<<X;
		I++;
	}
	printf("\n\n");
	fclose(Ft);
}
void Copy(FILE *Fi,FILE *Fj)
{
	fscanf(Fi,"%3d",&X);
	fprintf(Fj,"%3d",X);
	if( !feof(Fi))
	{
		fscanf(Fi,"%3d",&Y);
		long curpos = ftell(Fi)-2;
		fseek(Fi, curpos, SEEK_SET);
	}
	if (feof(Fi)) Eor = 1;
	else Eor = (X > Y)? 1 : 0 ;
}
void Distribute()
{
	do
	{
		CopyRun(F0,F1);
		if( !feof(F0)) CopyRun(F0,F2);
	}while( !feof(F0));
	fclose(F0);
	fclose(F1);
	fclose(F2);	
}
void CopyRun(FILE *Fi,FILE *Fj)
{
	do
	Copy(Fi,Fj);
	while ( !Eor);
}
void MergeRun()
{
	do
	{
		fscanf(F1,"%3d",&X1);
		long curpos = ftell(F1)-2;
		fseek(F1,curpos,SEEK_SET);
		fscanf(F2,"%3d",&X2);
		curpos = ftell(F2)-2;
		fseek(F2,curpos,SEEK_SET);
		if(X1 <= X2)
		{
			Copy(F1,F0);
			if(Eor) CopyRun(F2,F0);
		}
		else
		{
			Copy(F2,F0);
			if(Eor) CopyRun(F1,F0);
		}
	}while ( !Eor);
}
void Merge()
{
	while((!feof(F1)) && (!feof(F2)))
	{
		MergeRun();
		M++;
	}
	while( !feof(F1))
	{
		CopyRun(F1,F0);
		M++;
	}
	while(!feof(F2))
	{
		CopyRun(F2,F0);
		M++;
	}
	fclose(F0);
	fclose(F1);
	fclose(F2);
}



