#include <bits/stdc++.h>
using namespace std;
int kiemtra(int a[],int cuoi,int n)
{
    if(dau>n)
    {
     for (int i=dau;i<=n;i++)
        if (a[dau]>a[n]) dem++;
    }
}
int main()
{   int n;
    cin>>n;
    int a[n];
        for(int i=1;i<=n;i++)
            cin>>a[i];
    int cuoi=n-1;
    int kq=kiemtra(a,cuoi,n);
    cout<<kq;

    return 0;
}
