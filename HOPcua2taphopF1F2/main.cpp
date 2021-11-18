#include <bits/stdc++.h>
using namespace std;
struct  Nut
    {
        int info;
        Nut* Next;
    };
Nut *f1;
Nut *f2;
Nut *f3;
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
void NhapDLf1()
{
    int n;
    cout<<"nhap n = ";
    cin>>n;
    f1 = NULL;
    for(int i=1;i<=n;i++)
    {   int x;
        cout<<"x"<<i<<"= ";
        cin>>x;
        ChenDau(f1,x);
    }
}
void NhapDLf2()
{
    int n;
    cout<<"nhap n = ";
    cin>>n;
    f2 = NULL;
    for(int i=1;i<=n;i++)
    {   int x;
        cout<<"x"<<i<<"= ";
        cin>>x;
        ChenDau(f2,x);
    }
}
void Hop(Nut *&f3)
{
    Nut *p=f3;
    if (p==NULL) return;
    else {
        while(p->Next!=NULL)
        {
            if (p->info == p->Next->info)
            {
                Nut *q=p->Next;
                p->Next=q->Next;
                delete q;
            }
         p=p->Next;
        }
    }
}
void LietKe(Nut *f)
{
    Nut *p = f;
   // if (p==NULL) cout<<"Danh Sáº¡ch Rong"<<endl;
    while(p!=NULL)
    {
        cout<<p ->info<<endl;
        p = p ->Next;
    }
}

void taonutf3(Nut *&f3,Nut *f1,Nut *f2)
{   f3= NULL;
    Nut*p=f1;
    Nut*q=f2;
    if(p==NULL && q==NULL) return;
    while (p!=NULL || q!=NULL)
    {
        if(p!=NULL && q!=NULL)
        {
            if(p->info < q->info)
                {
                int x=p->info;
                ChenCuoi(f3,x);
                p=p->Next;
                }
            else
                {
                int x=q->info;
                ChenCuoi(f3,x);
                q=q->Next;
                }
        }
        if(p==NULL && q!=NULL)
        {
            int x=q->info;
            ChenCuoi(f3,x);
            q=q->Next;
        }
        if(p!=NULL && q==NULL)
        {
            int x=p->info;
            ChenCuoi(f3,x);
            p=p->Next;
        }
    }

    Hop(f3); // hop 2 danh sach xoa vi tri trung
}

int main()
{   cout<<"Nhap du lieu f1"<<endl;
    NhapDLf1();
    cout<<"Nhap du lieu f2"<<endl;
    NhapDLf2();

    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Danh sach f1"<<endl;
    LietKe(f1);

    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Danh sach f2"<<endl;
    LietKe(f2);

    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"Danh sach f3 hop cua hai tap hop f1 va f2 la"<<endl;
    taonutf3(f3,f1,f2); // ghep t danh sách
    LietKe(f3);
    return 0;
}
