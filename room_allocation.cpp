#include <bits/stdc++.h>
using namespace std;

struct person{
    person(){}
    long unsigned int s;
    long unsigned int e;
    long int r=-1;
    long int og_ind = -1;
    bool come;

};
bool mycom(pair<pair<long unsigned int, bool>, person*>& p1, pair<pair<long unsigned int,bool>, person*>& p2){
    
    if(p1.first.first == p2.first.first){
        return p1.first.second == 1;
    }
    return p1.first.first < p2.first.first;
}
int main()
{   long unsigned int n;
    cin>>n;
    long unsigned int start,end;
    vector<pair<pair<long unsigned int, bool>,person*>> v;
    for(long unsigned int i=0;i<n;i++){
        cin>>start;
        cin>>end;
        person* p = new person;
        p->s = start;
        p->e = end;
        p->r = -1;
        p->og_ind = i;
        v.push_back({{start, 1},p});
        v.push_back({{end,0},p});
        // v[2*i].second->s = start;
        // v[2*i].second->e = end;
        // v[2*i].second->og_ind = i;
        // v[2*i].second->r = -1;
        
        // v[2*i+1].first = end;
        // v[2*i].second = p;
        // v[2*i+1].second = p;
        // v[2*i+1].second = v[2*i].second;
        // v[2*i+1].second.s = start;
        // v[2*i+1].second.e = end;
        // v[2*i+1].second.og_ind = i;
        // v[2*i+1].second.r = -1;
    }
    long unsigned int num_rooms=0;
    vector<long unsigned int> unoccupied;
    vector<long unsigned int> ans(n);
    sort(v.begin(), v.end(), mycom);
    // for(int i=0;i<2*n;i++){
    //     cout<<v[i].second->og_ind<<" "<<v[i].first<<" "<<v[i].second->r<<endl;
    // }

    for(long unsigned int i=0;i<v.size();i++){
        if(v[i].second->r > -1)
        {   // cout<<"unoccupied room "<<v[i].second->r<<endl;
            unoccupied.push_back(v[i].second->r);
        }
        else{
            if(unoccupied.empty()){
                num_rooms++;
                ans[v[i].second->og_ind] = num_rooms;
                v[i].second->r = num_rooms;
                // cout<<"rooms increased to "<<num_rooms<<endl;
            }
            else{
                long unsigned int r = unoccupied[unoccupied.size()-1];
                unoccupied.pop_back();
                ans[v[i].second->og_ind] = r;
                v[i].second->r = r;
                // cout<<"allocated room "<<r<<endl;
            }
        }
    }
    cout<<num_rooms<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}