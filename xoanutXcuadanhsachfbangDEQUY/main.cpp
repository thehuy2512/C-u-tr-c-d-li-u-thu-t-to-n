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
    while(p!=NULL)
    {
        cout<<p ->info<<endl;
        p = p ->Next;
    }
}
void Xoadequy(Nut *&f,int x)
{
    if ((f!=NULL)&&(x>=f->info))
    {
        if(f->info==x)
            XoaDau(f);
        else Xoadequy(f ->Next,x);
    }
}
int main()
{
    NhapDL();
    cout<<"------------------------------------------------------------------------"<<endl;
    LietKe(f);
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<" xoa x=5 "<<endl;
    Xoadequy(f,5);
    LietKe(f);

    return 0;
}
