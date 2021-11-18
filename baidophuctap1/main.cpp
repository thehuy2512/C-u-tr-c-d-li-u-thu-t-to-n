#include <stdio.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>maxi) maxi=a[i];
    }

    cout<<maxi;
    return 0;
}


