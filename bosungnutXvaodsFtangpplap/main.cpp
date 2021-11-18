#include <bits/stdc++.h>
using namespace std;
struct  Nut
    {
        int info;
        Nut* Next;
    };
Nut *f;
void ChenDau(Nut *&f, int x)
{
    Nut *p = new Nut;
    p ->info = x;
    p ->Next = f;
    f=p;
}
void BS(Nut *&f,int x)
{
   /* Nut *p=f;
	while(p!=NULL)
	{
    if(p->Next->info >= x)
	{Nut *q=new Nut;
        q->info=x;
        q->Next=p->Next;
        p->Next=q;
			return;
    }
    p=p->Next;
	} */
    if(f==NULL || x<= f->info)
        ChenDau(f,x);
    else {
        Nut *q = new Nut;
        q->info = x;
        Nut *p=f;
        while (p->Next!=NULL&& p->Next->info <x)
            p=p->Next;
        q->Next= p->Next;
        p->Next= q;
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
    if(f!=NULL)
    {

        cout<< f->info <<endl;
        LietKe(f->Next);
        // viet nguoc lai de in nguoc day
    }
}

int main()
{
    NhapDL();
    cout<<"------------------------------------------------------------------------"<<endl;
    LietKe(f);
    cout<<"------------------------------------------------------------------------"<<endl;
    BS(f,6);
    cout<<"sau khi them x=6 la"<<endl;;
    LietKe(f);
    return 0;
}
