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
int LaTangDan(Nut *f)
{   Nut *p =f;
    if ((p==NULL) || (p->Next == NULL ) ) return 1;
    else
    {
    while(p!=NULL )
        {
        if(p->info > p->Next->info) return 0;
        p=p->Next;

        return 1;
        }
    }
}
int main()
{
    NhapDL();
    cout<<"------------------------------------------------------------------------"<<endl;
    LietKe(f);
    cout<<"------------------------------------------------------------------------"<<endl;

    if (LaTangDan(f)==0) cout<< "Day khọng phai la day tang dan";
    else cout<<"Day nay la day tang dan";
    return 0;
}
