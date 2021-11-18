#include <bits/stdc++.h>
using namespace std;
struct Nut
{
    int info;
    Nut *Left, *Right;
};
Nut *T;
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
int SoNutNhanh(Nut *T)
     {
         if (T==NULL) return 0;
         else   {
                if (T->Left==NULL && T->Right==NULL) return 0;
                else {
                        if (T->Left !=NULL && T->Right != NULL) return SoNutNhanh(T->Left) + SoNutNhanh(T->Right) + 1;
                        else {
                                if(T->Left==NULL) return 1 + SoNutNhanh(T->Right);
                                else return 1 + SoNutNhanh(T->Left);
                        }
                    }
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
    cout<<"so nut nhanh la: "<<endl;

    int kq= SoNutNhanh(T)-1;
    cout<<kq<<endl;
    // trừ 1 vì nút gốc không phải là nút nhánh
    return 0;
}
