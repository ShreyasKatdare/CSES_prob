#include <bits/stdc++.h>
using namespace std;

// set<int> helper(int *a, int n)
// {   //cout<<"hello"<<n<<" "<<a[0]<<endl;
//     if(n==1){
//         set<int> s;
//         s.insert(a[0]);
//         return s;
//     }
//     set<int> s = helper(a+1, n-1);
//     int b[s.size()];
//     int t = 0;
//     for(auto i:s){
//         //s.insert(a[0]+i);
//         b[t++] = i;
//     }
//     for(int kk =0;kk<s.size();kk++){
//         s.insert(b[kk]+a[0]);
//     }
//     s.insert(a[0]);
//     return s;
// }

int main()
{   int n;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    set<int> ans;
    for(int i=0;i<n;i++){
        int b[ans.size()]; int t=0;
        int xxx= ans.size();
        for(auto j:ans){
            b[t++] = j;
        }
        for(int j=0;j<xxx;j++){
            ans.insert(coins[i]+b[j]);
        }
        ans.insert(coins[i]);
    }
    
    
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }





    return 0;
}