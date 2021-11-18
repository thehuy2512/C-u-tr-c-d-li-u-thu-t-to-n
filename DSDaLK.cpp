#include<bits/stdc++.h>
using namespace std;

typedef char st25[25];
typedef char st8[8];

struct HocSinh
{
	int MaHS;
	st25 HoTen;
	st8 NgaySinh;
	HocSinh *Next;	 
} ;
struct Lop 
{
	Lop *Down;
	st8 TenLop;
	HocSinh * DSHS;
};
Lop *F;

// cau a 
Lop *DC(Lop *F, st8 Blop){
	if(F != NULL){
		if(strcmp(F->TenLop , Blop) == 0)
			return F;
		else 
			return DC(F->Down, Blop);
	}
	return NULL;
}

// cau b
void InDSLop(Lop *F, st8 Blop){
	Lop* P = DC(F, Blop);
	if(P != NULL){
		HocSinh *HS = P->DSHS;
		int stt = 1;
		cout<<"Danh sach lop: "<<F->TenLop <<endl;
		cout<<"Danh Sach Hoc Sinh"<<endl; 
		cout<<"STT		MaHs		HoTen		NgaySinh "<<endl;
		cout<<"--------------------------------------------"<<endl;
		if(HS == NULL)
			return;
		else{
			while (HS != NULL){
				cout <<stt <<"\t"<<HS->MaHS <<"\t"<<HS->HoTen <<"\t"<<HS->NgaySinh <<endl; 
				stt++;
				HS = HS->Next;
			}
  		}
	}
}

// Cau c 
int SiSo(Lop *F, st8 BLop){
	Lop *P = DC(F, BLop);
	if (P!= NULL){
		HocSinh *Tam = P->DSHS;
		int dem = 0;
		while(Tam != NULL){
			dem++;
			Tam = Tam->Next;
		}
		return dem;
	}
	return 0;
}

// cau d 
int InSiSoCacLop(Lop *F)
{
	if(F == NULL)
		return 0;
	else{
		int tong = 0, stt = 1;
		while(F != NULL){
			int sohs = SiSo(F,F->TenLop);
			cout<<"\t\tDanh sach si so cac lop"<<endl;
			cout<<stt<<".Lop "<<F->TenLop<<": "<<sohs <<"HS\n";
			stt++;
			tong += sohs;
			F = F->Down;
		}
		cout<<"----------------------\n";
		cout<<"Tong cong: "<<tong <<"HS\n";
	}
}

// cau e 
void BSHS(HocSinh *&L, st8 BLop , int BMaHS , st25 BHoTen, st8 BNgaySinh){
	HocSinh *P= new HocSinh;
	P->MaHS = BMaHS;
	strcpy(P->HoTen, BHoTen);
	strcpy(P->NgaySinh, BNgaySinh);
	P->Next= NULL;
	while (L->Next != NULL){
		L = L->Next; 
	}
	L->Next = P;
}
HocSinh *TimMaHS(HocSinh *L, int BMaHS){
	if(L == NULL)
		return NULL;
	else{
		if(strcmp(P->MaHS, BMaHS) == 0)
			return L;
		else
			return TimMaHS(L->Next, BMaHS);
	}	
}
void BS(Lop *&F, st8 BLop , int BMaHS , st25 BHoTen, st8 BNgaySinh)
{	
	Lop *L = DC(F, BLop);
	if(L == NULL){
		Lop *Q = new Lop;
		strcpy(Q->TenLop, BLop);
		Q->Down = F;
		F = Q;
		BSHS(F->DSHS, BLop , BMaHS , BHoTen, BNgaySinh);
	}
	else{
		HocSinh *P = L->DSHS;
		if(P == NULL){
			BSHS(L->DSHS, BLop , BMaHS , BHoTen, BNgaySinh)
		}
		else{
			strcpy(P->HoTen, BHoTen);
			strcpy(P->NgaySinh, BNgaySinh);
		}
	}
}

// cau g 
void XoaHS(HocSinh *&L, int BMaHS){
	if(L != NULL){
		if(L->MaHS == BMaHS){
			HocSinh *P = L; 
            L=L->Next; 
			delete P; 
    	}
		else 
    		return XoaHS(L->Next, BMaHS);
    }
}

// cau h 
void Xoa(Lop *&F, st8 Blop, int BMaHS){
	if(F != NULL){
		if(strcmp(F->TenLop ,Blop) == 0){
			XoaHS(F->DSHS, BMaHS);
            if(F->DSHS == NULL){
				Lop *P = F;
				F = F->Down; 
				delete P;
			}
		}
        else
			Xoa(F->Down, Blop, BMaHS);
    }
}

// nhap du lieu
//void nhap(){
//	int n,m;
//	cout<<"nhap so lop: ";
//	cin>>n;
//	for(int i = 0, i<n, i++){
//		cout<<"nhap ten lop: ";
//		cin>>F->TenLop;
//		cout<<"nhap so hoc sinh: ";
//		cin>>m;
//		for()
//	}
//}

int main(){
	nhap();
	
}


