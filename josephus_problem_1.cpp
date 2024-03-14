#include <bits/stdc++.h>
using namespace std;
int main()
{   int n;
    cin>>n;
    int start1 = 1,start2 = 3;
    int start = 2;
    int k =2;
    int count = 0;
    vector<bool> alive(n+1,1);
    for(;count < n-1;){
        bool f =0; // f denotes whether greatest number remaining killed in this iteration ?
        for(int i = start; i<=n;){
            alive[i] = 0;
            cout<<i<<" ";
            count++;
            i += k;
            if(i>n && i-k/2 <=n && alive[i-k/2] ){
                f=1;
            }
        }
        if(!f){
            start = start2;
            if(start1 + 2*k <= n)
                start2 = start1 + 2*k;
            else{
                start2 = (start1 + 2*k)%n;
            }
            if(start1>start2){
                int t = start1;
                start1 = start2;
                start2 = t;
            }
            //cout<<"\n choosing 2 start1 = "<<start1<<" start2 = "<<start2<<" start = "<<start<<endl;
        }
        else{
            start = start1;
            start1 = start2;
            if(start2 + 2*k <= n)
                start2 += 2*k;
            else{
                start2 = (start2+2*k)%n;
            }
            if(start1>start2){
                int t = start1;
                start1 = start2;
                start2 = t;
            }
            //cout<<"\n choosing 1 start1 = "<<start1<<" start2 = "<<start2<<" start = "<<start<<endl;
        }

        k *=2;
    }
    for(int i=1;i<=n;i++){
        if(alive[i]){
            cout<<i;
            break;
        }
    }


    return 0;
}