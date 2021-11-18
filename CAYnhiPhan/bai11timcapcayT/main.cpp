#include <bits/stdc++.h>
using namespace std;
struct Nut
{
    int info;
    Nut *Left, *Right;
};
Nut *T;
//Nut *L;
void BS(Nut *&T,int x)
    {
        if (T==NULL) {
            T= new Nut;
            T->info=x;
            T->Left=T->Right=NULL;
        }
        else {
            if (x<T->info) BS(T->Left,x);
            else BS(T->Right,x);
        }
    }
void LietKeGiua(Nut *T)
        {
            if (T!=NULL)
            {
              LietKeGiua(T->Left);
              cout<< T->info <<endl;
              LietKeGiua(T->Right);
            }

        }
void Duyetgiua(Nut *T,int &kt)
{
    if (T!=NULL)
    {
        if( T->Left != NULL && T->Right != NULL) kt=2;
        if( T->Left != NULL && T->Right = NULL) kt=1;
        if( T->Left = NULL && T->Right != NULL) kt=1;
        Duyetgiua(T->Left,kt);
        Duyetgiua(T->Right,kt);
    }
}
int Cap(Nut *T)
{
	int kt=0;
	Duyetgiua(T,kt);
	return kt;
}
void NhapDL()
    {
        int n,x;
        cout<<"n=";
        cin>>n;
        T = NULL;
        for(int i=1;i<=n;i++)
        {
            cout<<"x"<<i<<"=";
            cin>>x;
            BS(T,x);
        }
    }

int main()
{
    NhapDL();
    cout<<" KQSX:"<<endl;
    LietKeGiua(T);
    cout<<"-------------------------------------------------------"<<endl;
   // cout<<"cay L la:"<<endl;
    //TaoCayL(T,L);
   // LietKeGiua(L);
    cout<<Cap(T)<<endl;
    return 0;
}
