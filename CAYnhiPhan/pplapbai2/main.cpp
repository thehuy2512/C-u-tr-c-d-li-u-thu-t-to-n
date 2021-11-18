#include <bits/stdc++.h>
using namespace std;
struct Nut
{
    int info;
    Nut *Left, *Right;
};
Nut *T;
/*void BS(Nut *&T,int x)
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
*/
// viet ham bor sung bằng pp lặp
void BoSungLap(Nut*&T,int x)
    {   Nut * q = new Nut;
        q->info=x;
        q->Left=q->Right=NULL;
        Nut * p = T;
        if (T==NULL)
            T= q;
        while(p!=NULL)
       {
        if (x < p->info )
            p=p->Left;
        if (x >= p->info)
            p=p->Right;
       }
       // chạy đến hết nhanh . p dang null

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
          //  BS(T,x);
          BoSungLap(T,x);
        }
    }

int main()
{
    NhapDL();
  //  cout<<" KQSX:"<<endl;
    LietKeGiua(T);
    return 0;
}
