#include <bits/stdc++.h>
using namespace std;
void Xoa(int a[],int &d,int n,int x)
{
if (a[d]!=x && d<n) {
    cout<<a[d]<<' ';
    d=d+1;
    Xoa(a,d,n,x);
}
else {
    d=d+1;
    Xoa(a,d,n,x);
}
}
int main()
{
    int n,x;
    cin>> n >> x ;
    int a[n];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int d=1;
    Xoa(a,d,n,x);
  //  for(int i=1;i<=n;i++)
  //      cout<<a[i]<<' ';
    return 0;
}
