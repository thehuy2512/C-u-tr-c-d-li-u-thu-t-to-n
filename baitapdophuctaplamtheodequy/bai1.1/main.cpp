#include <bits/stdc++.h>
using namespace std;
int LN(int a[],int n)
{
    if (n==1) return a[1]; // neu chi có 1 gia tri thi no lon nhat
    else {
        int tamthoi=LN(a,n-1);
        if (tamthoi> a[n]) return tamthoi; // lon nhat doan n-1 so với n
        else return a[n];
        }
}
int main()
{   int n;
    cin>>n;
    int a[n];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int kq=LN(a,n);
        cout<<kq;
    return 0;
}
