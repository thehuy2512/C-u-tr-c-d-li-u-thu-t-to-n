#include <bits/stdc++.h>
using namespace std;
struct  Nut
    {
        int info;
        Nut* Next;
    };
Nut *f;
Nut *L;
void ChenDau(Nut *&f, int x)
{
    Nut *p = new Nut;
    p ->info = x;
    p ->Next = f;
    f=p;
}
void ChenCuoi(Nut *&f,int x)
{
    if(f==NULL) ChenDau(f,x);
    else ChenCuoi(f->Next,x);
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
   // if (p==NULL) cout<<"Danh Sạch Rong"<<endl;
    while(p!=NULL)
    {
        cout<<p ->info<<endl;
        p = p ->Next;
    }
}

void taonutL(Nut*f, Nut *&L)
{
    L = NULL;
    Nut *p= f;
    while(p!=NULL)
    {   int x=p->info;
        ChenCuoi(L,x);
        p=p->Next;
    }

}
int main()
{
    NhapDL();
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Danh sach f"<<endl;
    LietKe(f);
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Danh sach L"<<endl;
    taonutL(f,L);
    LietKe(L);
    return 0;
}
