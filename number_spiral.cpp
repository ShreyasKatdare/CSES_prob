#include <bits/stdc++.h>
using namespace std;
int main()
{   long long unsigned int t;
    cin>>t;
    long long unsigned int x,y;
    for(long long unsigned int i=0;i<t;i++){
        cin>>x>>y;
        if(x>=y){
            if(x%2==0)
                cout<<x*x-y+1<<endl;
            else
                cout<<x*x-2*x+1+y<<endl;
        }
        else{
            if(y%2==1)
                cout<<y*y-x+1<<endl;
            else
                cout<<y*y-2*y+1+x<<endl;
        }
    }

    return 0;
}