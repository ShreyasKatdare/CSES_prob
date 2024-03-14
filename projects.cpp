#include <bits/stdc++.h>
using namespace std;
struct project{
    long long start;
    long long end;
    long long money;
};

bool mycom(const project& a, const project&b){
    return a.start < b.start;
}

// long long reward(long long *a, long long j, vector<project> &p){
//     cout<<"hello j = "<<j<<endl;
//     if(a[j] != -1){
//         return a[j];
//     }
//     long long k;
//     for(k=j+1;k<p.size() && p[k].start <= p[j].end;k++){

//     }
//     cout<<"hello k = "<<k<<endl;
//     if(k<p.size()){
        
//         return max(reward(a, j+1, p), p[j].money+reward(a,k,p));
//     }
//     else{
//         cout<<"yo2\n";
//         return max(reward(a,j+1,p), p[j].money);
//     }
// }

int main()
{   long long n;
    cin>>n;
    vector<project> p(n);
    for(long long i=0;i<n;i++){
        cin>>p[i].start>>p[i].end>>p[i].money;
    }
    sort(p.begin(), p.end(), mycom);
    long long a[n];
    for(long long i=0;i<n;i++){
        a[i]=-1;
    }
    a[n-1] = p[n-1].money;
    // cout<<"began !\n";
    // cout<<reward(a,0,p);
    long long k;
    // multiset<long long> starts;
    // for(int i=0;i<n;i++){
    //     starts.insert(p[i].start);
    // }

    for(long long j = n-2; j>=0; j--){
        // for(k=j+1;k<p.size() && p[k].start <= p[j].end;k++){}
        // TODO : Replace above line with binary search on end times to find smallest end time greater than given time
            long long l = j+1, h = n-1, mid;
            bool f=0;
            while(l<=h){
                mid = l + (h-l)/2;
                if(p[mid].start <= p[j].end){
                    l = mid+1;
                }
                else if (p[mid].start > p[j].end && p[mid-1].start <= p[j].end){
                    k = mid;
                    f=1;
                    break;
                }
                else{
                    h = mid-1;
                }
            }
            if(!f){
                k=n;
            }
            // auto it = starts.upper_bound(p[j].end);
            // k = distance(starts.begin(), it);
            // cout<<"j = "<<j<<" k = "<<k<<endl;
            if(k < n){
                
                a[j] =  max(a[j+1], p[j].money+a[k]);
            }
            else{
                
                a[j] = max(a[j+1], p[j].money);
            }
        }

    cout<<a[0];
    return 0;
}