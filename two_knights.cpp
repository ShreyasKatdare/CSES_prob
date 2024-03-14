#include <bits/stdc++.h>
using namespace std;
int main()
{   long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cout<<(i-1)*(i*i*i + i*i -8*i+16)/2<<endl;
    }


    return 0;
}