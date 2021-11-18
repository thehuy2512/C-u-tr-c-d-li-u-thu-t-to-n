#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    float n,x;
    cin>>n>>x;
    float  s = 1;
    float  p = 1;
   for (int i = 1;i<= n;i++) {
 	p = p*x/ i;
	s += p;
}
    cout<<s;
    return 0;
}




