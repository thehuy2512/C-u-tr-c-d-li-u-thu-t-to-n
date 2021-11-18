#include <bits/stdc++.h>
#include<math.h>
using namespace std;
void doi(int so, int coso) {
    if (so != 0) {
        doi(so / coso, coso);
        cout << "0123456789ABCDEF"[so % coso];
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<"doi sang he 2"<<endl;
    doi(n,2);cout<<endl;
    cout<<"doi sang he 16"<<endl;
    doi(n,16);cout<<endl;
    cout<<"doi sang he 8"<<endl;
    doi(n,8);
    return 0;
}
