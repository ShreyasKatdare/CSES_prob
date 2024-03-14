#include <bits/stdc++.h>
using namespace std;
// int reward(int j, vector<vector<int>>& dp, int budget, int* price, int* pages, int n)
// {   if(j>=n || budget<=0) return 0;
//     if(dp[j][budget] != -1) return dp[j][budget];
//     if(budget-price[j]>=0){
//         dp[j][budget] = max(pages[j]+reward(j+1,dp,budget-price[j],price,pages,n), reward(j+1,dp,budget,price,pages,n));
//     }
//     else{
//         dp[j][budget] = reward(j+1,dp,budget,price,pages,n);
//     }
//     return dp[j][budget];
// }
// int main()
// {   int n, budget;
//     cin>>n>>budget;
//     int price[n], pages[n];
//     for(int i=0;i<n;i++){cin>>price[i];}
//     for(int i=0;i<n;i++){cin>>pages[i];}
//     vector<vector<int>> dp(n, vector<int> (budget+1));
    
//     for(int i = 0;i<n;i++){
//         for(int j=0;j<=budget;j++){
//             if(j==0){
//                 dp[i][j] = 0;
//             }
//             else{
//                 dp[i][j] = -1;
//             }
//         }

//     }
    
//     cout<<reward(0,dp,budget, price, pages, n);

//     return 0;
// }


int main(){
    int n, budget;
    cin>>n>>budget;
    int price[n], pages[n];
    for(int i=0;i<n;i++){cin>>price[i];}
    for(int i=0;i<n;i++){cin>>pages[i];}
    vector<vector<int>> dp(n+1, vector<int> (budget+1));
    
    for(int i = 0;i<=n;i++){
        for(int j=0;j<=budget;j++){
            if(j==0 || i==n){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }

    }
    for(int j = n-1;j>=0;j--){
        for(int bud = 1;bud<=budget;bud++){
            if(bud-price[j]>=0){
                dp[j][bud] = max(pages[j]+dp[j+1][bud-price[j]], dp[j+1][bud]);
            }
            else{
                dp[j][bud] = dp[j+1][bud];
            }
        }
    }

    cout<<dp[0][budget];

    return 0;
}