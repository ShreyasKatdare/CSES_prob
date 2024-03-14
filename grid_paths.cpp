#include <bits/stdc++.h>
using namespace std;
int main()
{   int n;
    cin>>n;
    int mod = int(1e9 + 7 );
    char grid[n][n];
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[n-1][n-1] == '*'){
        cout<<0;
        return 0;
    }
    int dp[n][n];
    bool f = 1;
    for(int i=n-1;i>=0;i--)
    {   if(grid[i][n-1] == '.' && f)
        {   dp[i][n-1] = 1;
        }
        else{
            f=0;
            dp[i][n-1] = 0;
        }

    }
    f=1;
    for(int i=n-1;i>=0;i--)
    {   if(grid[n-1][i] == '.' && f)
        {   dp[n-1][i] = 1;
        }
        else{
            f=0;
            dp[n-1][i] = 0;
        }
        
    }

    for(int i = n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--){
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i+1][j] + dp[i][j+1])%mod;
            }
        }
    }

    cout<<dp[0][0];

    return 0;
}