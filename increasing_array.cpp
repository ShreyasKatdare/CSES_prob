#include <bits/stdc++.h>
using namespace std;
int main()
{   long long int n;
    cin>>n;
    long long int a[n];
    for(long long int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int c=0;
    for(long long int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            c+= a[i]-a[i+1];
            a[i+1] = a[i];
        }
    }
    cout<<c;
    return 0;
}