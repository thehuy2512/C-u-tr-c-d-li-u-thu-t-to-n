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
void XoaDau(Nut *&f)
{
    if (f!=NULL)
    {
        Nut *p = f;
        f = f->Next;
        delete p;
    }
}
void Xoapplap(Nut *&f,int x)
{
  /*  if(f!=NULL)
  {

    Nut *p=f;
   // if (p->info )
   if(f->info==x) {



 f=f->Next;
    delete p;
   }
   else{
	while(p->Next!=NULL&&p->info<=x)
	{

   // if(p->Next->info >= x){
         if (p->Next->info == x)
      {
        Nut *q=p->Next;
        p->Next=q->Next;
        delete q;}
        return; // tim ra dung lai
    }
    p=p->Next;
	//}
   }
  } else return; */
  if (f==NULL || x < f->info) return;
  if (f->info==x) XoaDau(f);
  else {
    Nut *p=f;
    while(p->Next!=NULL && p->Next->info < x)
        p=p->Next;
    if (p->Next==NULL) return;
    else {
        if (p->Next->info==x)
        {
            Nut *q=p->Next;
            p->Next=q->Next;
            delete q;
        }
    }
  }
}
int main()
{
    NhapDL();
    cout<<"------------------------------------------------------------------------"<<endl;
    LietKe(f);
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"xoa gia tri x = 5"<<endl;
    Xoapplap(f,5);
    LietKe(f);

    return 0;
}
