#include <bits/stdc++.h>
using namespace std;
int kiemtra(int a[],int dau,int n)
{
    if (dau>n) return 1;
    else { if (a[dau]!=a[n]) return 0;
        else kiemtra(a,dau+1,n-1);
        }
}
int main()
{   int n;
    cin>>n;
    int a[n];
        for(int i=1;i<=n;i++)
            cin>>a[i];
   int dau=1;
   if (kiemtra(a,dau,n)==1) cout<<"doi xung";
   else cout<<"khong doi xung";
    return 0;
}
