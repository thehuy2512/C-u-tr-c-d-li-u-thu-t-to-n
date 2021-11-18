#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int n;
void Push(int s[],int &t,int x)
{
    if (t == n) cout<< "khong them duoc nua";
    else {
        t=t+1;
        s[t]=x;
    }
return ;
}
void Pop(int s[],int &t,int &x)
{

    if (t==0) cout<< "Stack can roi khong lay duoc nua";
    else {
        x= s[t];
        t=t-1;
    }
return ;
}
int main()
{
   // int n;
    int r;
    cin>>n;
    int t=0;
    int s[n];
    while (n!=0)
    {
        r=n%2;
        Push(s,t,n %2);
        n=n/2;
    }
    while (t!=0)
    {
        Pop(s,t,r);
        cout<< r;

    }
return 0;
}
