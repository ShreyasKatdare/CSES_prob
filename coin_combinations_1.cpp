#include <bits/stdc++.h>
using namespace std;

int main()
{   int n,sum;
    cin>>n>>sum;
    int coins[n];
    int mod = int(1e9 + 7 );
    for(int i =0;i<n;i++){
        cin>>coins[i];
    }
    vector<int> a(sum+1,0);
    a[0] = 1;
    for(int i =1;i<=sum; i++)
    {   int count = 0;
        for(int j = 0;j<n;j++){
            if(i-coins[j]>=0){
                count = (count + a[i-coins[j]])%mod;
            }
        }
        a[i] = count%mod;
    }
    // for(int i =0;i<=sum;i++){
    //     cout<<a[i]<<" ";
    // }
    cout<<a[sum];
}