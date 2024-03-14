#include <bits/stdc++.h>
using namespace std;

int main()
{   int n, m;
    cin>>n>>m;
    vector<int> tic(n), maxp(m);
    for(int i =0;i<n;i++){
        cin>>tic[i];
    }
    for(int i=0;i<m;i++){
        cin>>maxp[i];
    }
    
    vector<bool> valid(n,1);
    int l,h,mid;
    sort(tic.begin(), tic.end());
    for(int i=0;i<m;i++){
        
        l=0;h=n-1;
        int f=0;
        
        while(l<=h){
            mid=l+(h-l)/2;
            if(tic[mid]==maxp[i] && valid[mid]==1){
                
                cout<<tic[mid]<<endl;
                valid[mid]=0;
                f=1;
                break;
            }
            else if(tic[mid]==maxp[i] && valid[mid]==0){
                h = mid-1;
            }
            else if(tic[mid]>maxp[i]){
                h=mid-1;
            }
            else if(tic[mid]<= maxp[i] && tic[mid+1]>maxp[i] && valid[mid]){
                
                valid[mid]=0;
                cout<<tic[mid]<<endl;
                f=1;
                break;
            }
            else{
                l=mid+1;
            }
            
        }
        if(f==1){ 
            
        }
        else if(f==0 && tic[l]<=maxp[i] && valid[l]){
            
            cout<<tic[l]<<endl;
        }
        else{
            cout<<-1<<endl;        
        }
    }


    return 0;
}