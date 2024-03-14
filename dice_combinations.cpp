#include <bits/stdc++.h>
using namespace std;

// unsigned int helper(unsigned int *a, unsigned int n){
//     if(n<=0) return 0;
//     if(a[n]!=-1) return a[n];
    
//     return helper(a,n-1)+helper(a,n-2)+helper(a,n-3)+helper(a,n-4)+helper(a,n-5)+helper(a,n-6);
// }

int main()
{   unsigned int n; cin>>n;
    unsigned int count = 0;
    unsigned int mod=(1e9) + 7;
    
    if(n<=6){
        switch (n)
        {
        case 0:
            cout<<0;
            break;
        case 1:
            cout<<1;
            break;
        case 2:
            cout<<2;
            break;
        case 3:
            cout<<4;
            break;
        case 4:
            cout<<8;
            break;
        case 5:
            cout<<16;
            break;
        case 6:
            cout<<32;
            break;
        default:
            break;
        }
    }
    else{
        unsigned int a[n+1];
        
        a[0] = 0;
        a[1]=1;
        a[2]=2;
        a[3]=4;
        a[4]=8;
        a[5]=16;
        a[6]=32;
        unsigned int sum = 63;
        for(unsigned int i=7;i<=n;i++){
            a[i] = sum;
            sum = (sum + mod - a[i-6] + a[i]) % mod;

        }
        cout<<a[n];
    }
    
    //cout<<helper(a,n);
    return 0;
}