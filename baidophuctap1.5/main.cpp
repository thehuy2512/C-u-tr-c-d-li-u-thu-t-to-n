#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n]={0};
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-1;i++)
        { //  int tam=0;
            for(int j=i+1;j<=n;j++)
            {
                if (a[j]<=a[i]) b[i]=b[i]+1;
            }
          //  b[i]=tam;
        }
    b[n]=0;
    for(int i=1;i<=n;i++)
    cout<<b[i]<<' ';
    return 0;
}
