#include <bits/stdc++.h>
using namespace std;
struct  Nut
    {
        int info;
        Nut* Next;
    };
Nut *f;

void Push(int s[],int n,int &t,int x)
{
    if (t == n) cout<< "khong them duoc nua";
    else {
        t=t+1;
        s[t]=x;
    }
return ;
}
void Pop(int s[],int &t)
{

    if (t==0) cout<< "Stack can roi khong lay duoc nua";
    else {
        int  x= s[t];
        t=t-1;
        cout<<x<<endl;
    }
return ;
}
void ChenDau(Nut *&F,int x)
{
    Nut *p = new Nut;
    p ->info = x;
    p ->Next = f;
    f=p;
}
void LietKeStack(Nut*f,int n)
{   int t=0;
    int s[n];
    Nut * p= f;
    while(p!=NULL)
    {
        int x = p->info;
        Push(s,n,t,x);
        p=p->Next;
    }
    while (t!=0)
    {
        Pop(s,t);
    }
}
void LietKe(Nut *F)
{
    Nut *p = f;
    while(p!=NULL)
    {
        cout<<p ->info<<endl;
        p = p ->Next;
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
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Liet ke kieu thong thuong"<<endl;
    LietKe(f);
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Liet ke nguoc kieu stack"<<endl;
    LietKeStack(f,n);
}


int main()
{
    NhapDL();

    return 0;
}
