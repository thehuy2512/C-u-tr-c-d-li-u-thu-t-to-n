#include <bits/stdc++.h>
using namespace std;
void XuLy(int a[],int n)
    {
        int dem=1;
        for (int i=0;i<=n-1;i++)
        if (a[i]==a[i+1]) {
            dem=dem+1;

        }
        else {
            cout<<"So "<<a[i]<<" xuat hien :"<<dem<<" lan"<<endl;
            dem=1;
        }
    }
void Kq(int a[],int n)
{
    for(int i=0;i<=n-1;i++)
        cout<<a[i]<<endl;
}
void sapxep(int a[],int n)
    {
        for (int i=0;i<=n-2;i++)
            for (int j=i+1;j<=n-1;j++)
                if (a[i]>a[j]) {
                    int tam=a[i];
                    a[i]=a[j];
                    a[j]=tam;
                }
    }

int main()
{   int n;


    cout<<"nhap n=";
    cin>>n;
    int a[n];
    for (int i=0;i<=n-1;i++)
    {
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }

    sapxep(a,n);
    Kq(a,n);
    cout<<"-------------------------------------"<<endl;
    XuLy(a,n);
    return 0;
}
