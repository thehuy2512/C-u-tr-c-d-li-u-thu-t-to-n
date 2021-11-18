#include <bits/stdc++.h>
using namespace std;
struct Nut
{
    int info;
    Nut *Left, *Right;
};
Nut *T;
Nut *L;
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
void TaoCayL(Nut *T,Nut*&L)
    {   if (T==NULL) L=NULL;
        else {
            L= new Nut;
            L->info=T->info;
            L->Left=L->Right=NULL;
            if (T->Left!=NULL) TaoCayL(T->Left,L->Left);
            if (T->Right!=NULL) TaoCayL(T->Right,L->Right);
            }
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
    cout<<"cay L la:"<<endl;
    TaoCayL(T,L);
    LietKeGiua(L);

    return 0;
}
