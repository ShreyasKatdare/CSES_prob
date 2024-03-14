#include <bits/stdc++.h>
using namespace std;
int main()
{   int n,summ;
    cin>>n>>summ;
    int coins[n];
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }

    int a[summ+1];
    for(int i=0;i<=summ;i++){a[i]=-1;}
    a[0]=0;
    for(int i=1;i<=summ;i++){
        int sum=i;
        int my_min = INT_MAX;
        for(int j=0;j<n;j++){
            if(sum-coins[j] >=0 && a[sum-coins[j]]>=0){
                
                my_min = min(my_min, 1+a[sum-coins[j]]);
            }
        }
        
        if(my_min != INT_MAX ){
            a[i]=my_min;
        }
        
        

    }
    // for(int i=0;i<=summ;i++){
    //     cout<<a[i]<<" ";
    // }
    cout<<a[summ];
    return 0;
}