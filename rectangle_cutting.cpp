#include <bits/stdc++.h>
using namespace std;

int main()
{   int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0;
        return 0;
    }
    if(a<b){
        int t =a;
        a=b;
        b=t;
    }
    int dp[a+1][b+1];
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else if(i==2*j || j==2*i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }
    // cout<<"hello\n";
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(dp[i][j]==-1){
                int minn = INT_MAX;
                int k = 1;
                while(k<=j-k){
                    minn = min(minn, 1 + dp[i][k] + dp[i][j-k]);
                    k++;
                }
                k=1;
                while(k<=i-k){
                    minn = min(minn, 1+dp[k][j]+dp[i-k][j]);
                    k++;
                }
                dp[i][j] = minn;
            }
        }
    }
    // for(int i = 1;i<= a;i++){
    //     for(int j=1;j<=b;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[a][b];

    return 0;
}