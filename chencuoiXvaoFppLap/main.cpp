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
void ChenCuoippLap(Nut *&f,int x)
{
    Nut *p=f;
    Nut *q = new Nut;
	q->info=x;
	q->Next=NULL;
	while(p->Next!=NULL)
		p=p->Next;
	p->Next=q;
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


int main()
{
    NhapDL();
    cout<<"------------------------------------------------------------------------"<<endl;
    LietKe(f);
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"chen 3 vao cuoi danh sach f"<<endl;
    ChenCuoippLap(f,3);
    LietKe(f);

    return 0;
}
