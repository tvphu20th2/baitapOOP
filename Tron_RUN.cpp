#include <conio.h>
#include<stdio.h>

void Xuat_File(void);
void Tao_File(void);
void Tron(FILE *f0,FILE *f1,FILE *f2,int p);
void Chia(FILE *f0,FILE *f1,FILE *f2,int p);

int p,n;
int main()
{
	FILE *a,*b,*c;
	Tao_File();
	Xuat_File();
	p=1;
	while(p<n)
	{
		Chia(a,b,c,p);
		Tron(a,b,c,p);
		p=2*p;
	}
	printf("\n\n\n");
	Xuat_File();
	getch();
	return 0;
}

void Tao_File(void)  
{
	int i,x;
	FILE *fp;
	fp=fopen("Z:\\bang.txt","wb");
	printf("Cho biet so luong phan tu:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		fprintf(fp,"%3d",x);
	}
	fclose(fp);
}

void Xuat_File(void)
{
	int i,x;
	FILE *fp;
	fp=fopen("Z:\\bang.txt", "rb");
	i=0;
	while(i<n)
	{
		fscanf(fp,"%3d",&x);
		printf("%3d",x);
		i++;
	}
	fclose(fp);
	
}

void Chia(FILE *a,FILE *b,FILE *c,int p) 
{
	int dem,x;
	a=fopen("Z:\\bang.txt","rb");
	b=fopen("Z:\\bang1.txt","wb");
	c=fopen("Z:\\bang2.txt","wb");
	while(!feof(a))
	{               
		dem=0;
		while((dem<p)&&(!feof(a)))
		{
			fscanf(a,"%3d",&x);
			fprintf(b,"%3d",x);
			dem++;
		}
		dem=0;      
		while((dem<p)&&(!feof(a)))
		{
			fscanf(a,"%3d",&x);
			fprintf(c,"%3d",x);
			dem++;
		}
	}
	fclose(a); fclose(b); fclose(c);
}

void Tron(FILE *a,FILE *b,FILE *c,int p)
{        
	int stop,x,y,l,r;
	a=fopen("Z:\\bang.txt","wb");
	b=fopen("Z:\\bang1.txt","rb");
	c=fopen("Z:\\bang2.txt","rb");
	while((!feof(b))&&(!feof(c)))
    {
	    l=0;  
	    r=0;  
	    fscanf(b,"%3d",&x);
	    fscanf(c,"%3d",&y);
	    stop=0;
	    while((l!=p)&&(r!=p)&&(!stop))
	    {
	    	if(x<y)
	    	{
	    		fprintf(a,"%3d",x);
	    		l++;
	    		if(l<p&&(!feof(b)))  
	    		    fscanf(b,"%3d",&x);
	    		else
				{
					fprintf(a,"%3d",y);
					r++;
					if(feof(b))
					    stop=1;
				}    
			}
			else
			{
				fprintf(a,"%3d",y);
	    		r++;
	    		if(r<p&&(!feof(c)))  
	    		    fscanf(c,"%3d",&y);
	    		else
				{
					fprintf(a,"%3d",x);
					l++;
					if(feof(c))
					    stop=1;
				}    			
			}
		}
		
	while((!feof(b))&&(l<p))
	{
		fscanf(b,"%3d",&x);
		fprintf(a,"%3d",x);
		l++;
	}  
	while((!feof(c))&&(r<p))
	{
		fscanf(c,"%3d",&y);
		fprintf(a,"%3d",y);
		r++;
	}			
    }
    if(!feof(b))
    {    
    	while(!feof(b))
    	{
    		fscanf(b,"%3d",&x);
		    fprintf(a,"%3d",x);
		}
	}
	if(!feof(c))
	{    
		while(!feof(c))
		{
			fscanf(c,"%3d",&y);
	    	fprintf(a,"%3d",y);
		}
	}
	fclose(a); fclose(b); fclose(c);
}


