#include <bits/stdc++.h>
using namespace std;
int main()
{   int n,t;
    cin>>n;
    int a[n+1];
    for(int i = 0;i<n-1;i++){
        cin>>t;
        a[t]=1;
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            cout<<i;
            break;
        }
    }


    return 0;
}