#include <bits/stdc++.h>
using namespace std;
int mod = int(1e9 + 7);
int helper(vector<int> &a, int start, int n, int m, vector<vector<int>> &dp)
{   if(a[start]>m || a[start] <=0) return 0;
    if(dp[start][a[start]] != -1) return dp[start][a[start]];
    if(start == n-1) return dp[start][a[start]]=1;
    
    a[start+1] = a[start] -1;
    int c1 = helper(a, start+1, n,m,dp) % mod;
    a[start +1] = a[start];
    int c2 = helper(a, start+1, n,m, dp) % mod;
    a[start+1] = a[start] + 1;
    int c3 = helper(a,start+1,n,m,dp) % mod;
    a[start+1] = 0;
    return dp[start][a[start]] = ((c1+c2)%mod+c3)%mod;

}
int main()
{   int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> dp(n, vector<int> (m+1));
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == 0 || a[i] == j){
                dp[i][j] = -1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    if(a[0]!=0){
        cout<<helper(a,0,n,m,dp);
    }
    else{
        int c=0;
        for(int i=1;i<=m;i++){
            a[0] = i;
            c = (c + helper(a, 0, n,m,dp))%mod;
        }
        cout<<c;
    }

    return 0;
}