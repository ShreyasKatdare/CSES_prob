#include <bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(3);

    for(auto i:s){
        cout<<i;
    }
    return 0;
}