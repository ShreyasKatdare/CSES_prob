#include <bits/stdc++.h>
using namespace std;

bool mycom(pair<int,int> &a, pair<int, int> &b)
{   return a.first < b.first;

}

int main()
{   int n;
    cin>>n;
    int start;
    int end;
    if(n==0){
        cout<<0;
        return 0;
    }
    vector<pair<int,int>> intervals(n);
    for(int i=0;i<n;i++){
        cin>>start;
        cin>>end;
        intervals[i] = {start,end};
    }
    sort(intervals.begin(), intervals.end(), mycom);
    int ans = 1;
    priority_queue<int, vector<int>, greater<int>> ends;
    ends.push(intervals[0].second);
    for(int i=1;i<n;i++){
        if(ends.top() > intervals[i].first){
            ans++;
            ends.push(intervals[i].second);
        }
        else{
            ends.pop();
            ends.push(intervals[i].second);
        }

    }
    cout<<ans;
    return 0;
}