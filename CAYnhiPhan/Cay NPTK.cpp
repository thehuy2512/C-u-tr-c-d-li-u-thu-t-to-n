#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
struct Nut
{
	int Info;
	Nut *Left, *Right;
};
Nut *T;

//Ham tinh tong gia tri truong Info cua cac nut tren cay T
int Tong(Nut *T)
{
	if(T==NULL)
		return 0;
	else
		return T->Info + Tong(T->Left) + Tong(T->Right);
}

//Ham in ra man hinh cac gia tri truong Info tat ca cac nut tren cay T theo thu tu truoc
void LK(Nut *T)
{
	if(T!=NULL)
	{
		LK(T->Left);
		cout<<T->Info<<endl;		
		LK(T->Right);
	}
}

/*Nut *getNut(int x)
{
	Nut *p= new Nut;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Left=NULL;
	p->Right=NULL;
	return p;
}*/

//Bo sung 1 nut la x cho cay NPTK T
void BS(Nut *&T, int x)
{
	if(T==NULL){
	
		T= new Nut;
		T->Info=x;
		T->Left=T->Right=NULL;
	}
	else
	{
		if(x<T->Info)
			BS(T->Left,x);
		else
			BS(T->Right,x);
	}
}

//Xoa ALL nut tren cay NPTK T
void Xoa(Nut *T)
{
	if(T!=NULL)
	{
		Xoa(T->Right);
		Xoa(T->Left);
		Xoa(T);
		T=NULL;
	}
}

//Dem so nut trong cay T
int DemSoNut(Nut *T)
{
	if(T==NULL)
		return 0;
	else if (T->Left==NULL && T->Right==NULL)
		return 1;
		else
			return DemSoNut(T->Left)+DemSoNut(T->Right)+1;
}

//Ham tra ve dia chi trong cay T sao cho tra ve gia tri truong Info = x (Cay NPTK)
Nut * TimKiemNP(Nut *T, int x)
{
	if(T==NULL || T->Info==x)
		return T;
	if(T->Info>x)
		return TimKiemNP(T->Left,x);
	return TimKiemNP(T->Right,x);
}

//Ham tra ve dia chi trong cay T sao cho tra ve gia tri truong Info = x (Cay bat ki)
Nut * TimKiem(Nut *T, int x)
{
	if(T==NULL || T->Info==x)
		return T;
	Nut *p=TimKiem(T->Left,x);
	if(p!=NULL)
		return p;
	else
		return TimKiem(T->Right,x);
}

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

//Tinh Chieu cao h cua cay
int ChieuCao(Nut *T)
{
	if(T==NULL)
		return 0;
	else
		return max(ChieuCao(T->Left),ChieuCao(T->Right)) + 1;
}

//Tim gia tri lon nhat(gia thiet cay T co it nhat 1 nut) voi T la cay NPTK
int TimMaxNP(Nut *T)
{
	if(T->Right==NULL)
		return T->Info;
	else
		return TimMaxNP(T->Right);
}

//Tim gia tri lon nhat(gia thiet cay T co it nhat 1 nut) voi T la cay bat ky
int TimMax(Nut *T)
{
	//if(T->Left==NULL && T->Right==NULL)
	//	return T->Info;
	if(T==NULL)
		return -1;
	else if (T->Info > max(TimMax(T->Left),TimMax(T->Right)))
			return T->Info;
		else
			return max(TimMax(T->Left),TimMax(T->Right));
}

//Tim so nut nhanh trong cay
int SoNutNhanh(Nut *T)
{
	if(T==NULL)
		return 0;
	if((T->Left!=NULL&&T->Right!=NULL)||(T->Left!=NULL&&T->Right==NULL)||(T->Left==NULL&&T->Right!=NULL))
		return 1 + SoNutNhanh(T->Left) + SoNutNhanh(T->Right);
	else
		return SoNutNhanh(T->Left) + SoNutNhanh(T->Right);
}

//Tim dia chi cua nut cha duoc tro boi p trong cay T
Nut *Cha(Nut *T, Nut *p)
{
	if((T==NULL)&&(T==p))
		return NULL;
	else if ((T->Left==p)||(T->Right)==p)
			return Cha(T->Left,p);
		else
			return Cha(T->Right,p);
}

//In thu tu cac nut trong cay TKNP T theo thu tu giam dan
void GiamDan(Nut *T)
{
	if(T!=NULL)
	{
		GiamDan(T->Right);
		cout<<T->Info<<endl;
		GiamDan(T->Left);
	}
}

//Tao cay L (nut goc L) sao chep du lieu tu cay T

void TaoCay(Nut *T, Nut *&L)
{
	L = new Nut;
	L->Info = T->Info;
	L->Left=L->Right=NULL;
	if(T->Left!=NULL)
		return TaoCay(T->Left,L->Left);
	if(T->Right!=NULL)
		return TaoCay(T->Right,L->Right);
}

//Kiem tra cay T co phai nhi phan hay khong?
int KiemTra(Nut *T)
{
	if(T==NULL || T->Left==NULL && T->Right==NULL)
		return 0;
	if(T->Left!=NULL && T->Right==NULL)
		return (T->Info > TimMax(T->Left)) && KiemTra(T->Left);
	else if(T->Right!=NULL && T->Left==NULL)
			return(T->Info < TimMax(T->Left)) && KiemTra(T->Right);
		 else
		 	return(T->Info>TimMax(T->Left)&&T->Info<TimMax(T->Right))&&KiemTra(T->Left)&&KiemTra(T->Right);
}

void KiemTraKQ(Nut *T)
{
	int KT=KiemTra(T);
	if(KT==0)
		cout<<"T khong phai la cay nhi phan tim kiem";
	else
		cout<<"T la cay nhi phan tim kiem";
}

//Tim cap cua cay T. La cap 0 neu cay T rong hoac co 1 nut
int Cap(Nut *T)
{
	if(T==NULL || (T->Left==NULL && T->Right==NULL))
		return 0;
	else
		return DemSoNut(T)-1;
}

void NhapDL(Nut *&T)
{
	int n, x;
	cout<<"n=";
	cin>>n;
	T=NULL;
	for(int i=1;i<=n;i++)
	{
		cout<<"x"<<i<<"=";
		cin>>x;
		BS(T,x);
	}
}

main()
{
	Nut *L;
	L==NULL;
	NhapDL(T);
//	cout<<"Day duoc sap xep la:"<<endl;
//	LK(T);
	cout<<"Gia tri lon nhat tren cay bat ky la: "<<TimMaxNP(T)<<endl;
	cout<<"So nut trong cay la : "<<DemSoNut(T)<<endl;
	cout<<"So nut nhanh la: "<<SoNutNhanh(T)<<endl;
	TaoCay(T,L);
	cout<<"Kiem tra cay : "<<KiemTra(T)<<endl;
//	KiemTraKQ(T);
	cout<<"Cap cua cay T la : "<<Cap(T)<<endl;
	
}

