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
    if((f==NULL)||(x <= f->info))
        ChenDau(f,x);
    else BS(f->Next,x);
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
    BS(f,3);
    cout<<"sau khi them la"<<endl;;
    LietKe(f);
    return 0;
}
