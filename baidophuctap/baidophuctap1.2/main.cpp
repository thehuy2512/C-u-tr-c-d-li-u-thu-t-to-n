#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n/2;i++)
    {
        tam=a[i];
        a[i]=a[n+1-i];
        a[n+1-i]=tam;

    }
    for(int i=1;i<=n;i++)
        cout<<a[i];

    return 0;
}
