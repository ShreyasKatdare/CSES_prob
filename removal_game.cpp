#include <bits/stdc++.h>
using namespace std;

long long int player2(long long int *a, long long int start, long long int end, long long int tot_sum, vector<vector<long long int>>& p);


long long int player1(long long int *a, long long int start, long long int end, long long int tot_sum, vector<vector<long long int>>& p)
{   if(start == end) return a[start];
    if(end-start ==1) return max(a[start],a[end]);
    if(p[start][end] != -1) return p[start][end];
    long long int k = player2(a, start+1, end, tot_sum-a[start], p);
    long long int k2 = player2(a, start, end-1, tot_sum-a[end], p);
    p[start][end] = max(tot_sum - k, tot_sum - k2);
    return p[start][end];
}

long long int player2(long long int *a, long long int start, long long int end, long long int tot_sum, vector<vector<long long int>>& p)
{   if(start==end) return a[start];
    if(end - start==1) return max(a[start],a[end]);
    if(p[start][end] != -1) return p[start][end];
    long long int k = player1(a, start+1, end, tot_sum-a[start], p);
    long long int k2 = player1(a, start, end-1, tot_sum-a[end], p);
    p[start][end] = max(tot_sum - k, tot_sum - k2);
    return p[start][end];
}

int main()
{   long long int n;
    cin>>n;
    long long int a[n];
    long long int tot_sum = 0;
    for(long long int i=0;i<n;i++){cin>>a[i]; tot_sum+=a[i];}
    vector<vector<long long int>> p(n,vector<long long int>(n));
    for(long long int i = 0;i<n;i++){
        for(long long int j=0;j<n;j++){
            if(i==j){
                p[i][j] = a[i];
            }
            else if(j<i){
                p[i][j] = 0;
            }
            else{
                p[i][j] = -1;
            }
        }
    }
    cout<<player1(a,0,n-1,tot_sum,p);





    return 0;
}