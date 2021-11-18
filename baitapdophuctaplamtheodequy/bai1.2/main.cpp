#include <bits/stdc++.h>
using namespace std;
int daonguoc(int a[],int n)
{
    if (n==1) cout<<a[1];
    else {
        cout<<a[n]<<' ';
        daonguoc(a,n-1);
        }
}
int main()
{   int n;
    cin>>n;
    int a[n];
        for(int i=1;i<=n;i++)
            cin>>a[i];
    daonguoc(a,n);
    return 0;
}
