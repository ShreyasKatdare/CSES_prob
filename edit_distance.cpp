#include <bits/stdc++.h>
using namespace std;
int main()
{   int pp = 5100;
    char a[pp], b[pp];
    cin.getline(a, pp);
    cin.getline(b, pp);
    int m,n;
    for(m=0;a[m]!='\0';m++);
    for(n=0;b[n]!='\0';n++);
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=n;i++){
        dp[0][i] =i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = min(1+dp[i-1][j], 1+dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
            else{
                dp[i][j] = min(1+dp[i-1][j], 1+dp[i][j-1]);
                dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);
            }
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[m][n];


    return 0;
}