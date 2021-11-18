#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int kiemtra=1;
    for(int i=1;i<=n/2;i++)
    {
        if (a[i]!= a[n+1-i]) kiemtra=0;
    }
    if (kiemtra==0) cout<<"khong doi xung";
    else cout<<"doi xung";

    return 0;
}
