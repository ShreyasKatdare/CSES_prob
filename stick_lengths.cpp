#include <bits/stdc++.h>
using namespace std;
int main()
{   long long n;
    cin>>n;
    vector<long long> p(n);
    for(long long i=0;i<n;i++)
    {
        cin>>p[i];
    }
    sort(p.begin(), p.end());
    long long median = p[n/2];
    long long sum = 0;
    for(auto i : p){
        sum += abs(i-median);
    }
    cout<<sum;
    return 0;
}