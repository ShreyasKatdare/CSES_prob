#include <bits/stdc++.h>
using namespace std;
int main()
{   int n;
    cin>>n;
    int cubes[n];
    for(int i=0;i<n;i++){cin>>cubes[i];}
    multiset<int> s;
    s.insert(cubes[0]);
    int count = 1;
    for(int i=1;i<n;i++){
        if(*(s.rbegin())<=cubes[i]){
            count++;
            s.insert(cubes[i]);
        }
        else{
            auto it = s.upper_bound(cubes[i]);
            s.erase(it);
            s.insert(cubes[i]);
        }
    }
    
    
    cout<<count;
    // multiset<int> s;
    // s.insert(1);
    // s.insert(5);
    // s.insert(3);
    // for(auto i:s){
    //     cout<<i<<" ";
    // }
    // cout<<*s.upper_bound(2);
    return 0;
}