#include <bits/stdc++.h>
using namespace std;

int helper(int *a, int n){
    if(a[n]!=-1) return a[n];
    int p = n;
    a[n] = INT_MAX - 1;
    while(p>0){
        int d = p%10;
        a[n] = min(a[n], 1+helper(a,n-d));
        p/=10;
    }
    return a[n];
}
int main()
{   int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<=n;i++){
        a[i] = -1;
    }
    a[0] = 0;
    // int mod = int(1e9 + 7);
    // if(n==0){
    //     cout<<0;
    //     return 0;
    // }
    // if(n<=9){
    //     cout<<1;
    //     return 0;
    // }
    // int a[n+1];
    // a[0]=0;
    for(int i=1;i<=9;i++){
        a[i]=1;
    }
    // for(int i=10;i<=n;i++){
    //     int p = i;
    //     a[i] = INT_MAX - 1;
    //     while(p>0){
    //         int d = p%10;
    //         a[i] = min(a[i], 1 + a[i-d]);
    //         p /= 10;            
    //     }
    // }
    // for(int i =1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    cout<<helper(a,n);
    return 0;
}