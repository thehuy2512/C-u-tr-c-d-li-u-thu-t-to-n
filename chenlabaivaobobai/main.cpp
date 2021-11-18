#include <bits/stdc++.h>
using namespace std;
void BoSung(int a[],int &n,int x)
{
    if (n==0 || x >= a[n])
    {
        n++;
        a[n]=x;
    }
    else {
        a[n+1]=a[n];
        n=n-1;
        BoSung(a,n,x);
        n=n+1;
        }
}
int main()
{
    int n,x;
    cin>> n >> x ;
    int a[n];
    for(int i=1;i<=n;i++)
        cin>>a[i];

   BoSung(a,n,x);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    return 0;
}
