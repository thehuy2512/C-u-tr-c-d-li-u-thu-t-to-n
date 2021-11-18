#include <bits/stdc++.h>
using namespace std;
struct  Nut
    {
        int info;
        Nut* Next;
    };
Nut *f;
void ChenDau(Nut *&F, int x)
{
    Nut *p = new Nut;
    p ->info = x;
    p ->Next = f;
    f=p;
}
void XoaDau(Nut *&f)
{
    if (f!=NULL)
    {
        Nut *p = f;
        f = f->Next;
        delete p;
    }
}
void NhapDL()
{
    int n;
    cout<<"nhap n = ";
    cin>>n;
    f = NULL;
    for(int i=1;i<=n;i++)
    {   int x;
        cout<<"x"<<i<<"= ";
        cin>>x;
        ChenDau(f,x);
    }
}
void LietKe(Nut *f)
{
    Nut *p = f;
    if (p==NULL) cout<<"deo co so mo";
    while(p!=NULL)
    {
        cout<<p ->info<<endl;
        p = p ->Next;
    }
}
void Xoacuoipplap(Nut *&f)
{
    Nut *p=f;
    if(f==NULL) return;
    else
    {
            if(f->Next==NULL) XoaDau(f);
            else
                {while(p->Next->Next!=NULL)
                p=p->Next;
            // p dang o vi tri ap cuoi
                p->Next=NULL;
                }
    }
}
int main()
{
    NhapDL();
    cout<<"------------------------------------------------------------------------"<<endl;
    LietKe(f);
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"xoa cuoi"<<endl;
    Xoacuoipplap(f);
    LietKe(f);

    return 0;
}
