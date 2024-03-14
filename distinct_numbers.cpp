#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int k = int(1e9);
    vector<bool> hmm(k,0);
    int count=0;
    int a[n];
    // unordered_map<int,bool> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(hmm[a[i]] == 0){
            count++;
            hmm[a[i]] =1;
        }
        
    }
    cout<<count;
    return 0;
}