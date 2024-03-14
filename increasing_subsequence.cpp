#include <bits/stdc++.h>
using namespace std;

struct node{
    node(){
        left = NULL;
        right = NULL;
        val = -1;
        sum = -1;
    }
    node* left;
    int val;
    int sum;
    node*right;
};


int main()
{   int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>i;
    }
    int dp[n];
    dp[0] = 1;



    return 0;

}