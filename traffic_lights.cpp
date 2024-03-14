#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,x;
    cin>>n>>x;
    
    multiset<int, greater<int>> s;
    multiset<int, greater<int>> points;
    points.insert(0);
    points.insert(n);
    s.insert(n);
    int t[x];
    for(int i =0;i<x;i++){cin>>t[i];}
    for(int i = 0;i<x;i++){
        // cout<<t[i]<<endl;
        // for(auto i : points){cout<<i<<" ";}cout<<endl;
        auto prev = points.upper_bound(t[i]);
        auto next = prev--;
        // cout<<*prev<<" "<<*next<<"\n";
        auto it = s.find(*prev-*next);
        s.erase(it);
        s.insert(t[i]-*next);
        s.insert(*prev - t[i]);
        cout<<*s.begin()<<" ";
        points.insert(t[i]);
    }

    // multiset<int> s;
    // s.insert(1);
    // s.insert(5);
    // s.insert(3);
    // for(auto i:s){
    //     cout<<i<<" ";
    // }
    // cout<<*s.upper_bound(2);
    // cout<<*s.lower_bound(2);
    return 0;
}