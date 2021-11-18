#include <bits/stdc++.h>
#include<math.h>
using namespace std;
void doi(int a)
{
    if (a!=0)
    {
    doi(a/2);
    cout<<(a%2);
    }

}
int main()
{
    int n;
    cin>>n;
    doi(n);
    return 0;
}
