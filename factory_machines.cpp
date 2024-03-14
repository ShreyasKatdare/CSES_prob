#include <bits/stdc++.h>
using namespace std;
int main()
{   priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> times;
    long long n,k;
    cin>>n>>k;
    vector<long long> t(n);

    for(long long i=0;i<n;i++){
        cin>>t[i];
        times.push({t[i],t[i]});
    }

    for(long long j=1 ; j<=k-1;j++){
        auto t = times.top();
        times.pop();
        times.push({t.first + t.second, t.second});

    }

    cout<<times.top().first;

    return 0;
}