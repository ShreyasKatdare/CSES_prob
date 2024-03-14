#include <bits/stdc++.h>
using namespace std;
int main()
{   int n;
    cin>>n;
    int x;cin>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0,j=0;
    int sum = 0;
    int count=0;
    for(;j<n;j++){
        sum += a[j];
        if(sum==x){
            count++;
        }
        else if(sum > x){
            while(sum >= x){
                sum -= a[i++];
                if(sum==x) count++;
            }
        }
    }
    cout<<count;


    return 0;
}