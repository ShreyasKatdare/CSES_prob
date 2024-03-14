#include <bits/stdc++.h>
using namespace std;
int main()
{   int n;
    cin>>n;
    if(n%4 == 0 || n%4==3){
        cout<<"YES\n";
    }
    else{
        cout<<"NO";
        return 0;
    }
    if(n%4 == 0){
        cout<<n/2<<endl;
        for(int i=1;i<=n/4;i++){
            cout<<i<<" "<<n-i+1<<" ";
        }
        cout<<endl;
        cout<<n/2<<endl;
        for(int i=n/4+1; i<=n/2;i++){
            cout<<i<<" "<<n-i+1<<" ";
        }

    }
    else{
        cout<<n/2<<endl;
        cout<<n<<" ";
        for(int i=1;i<=n/4;i++){
            cout<<i<<" "<<n-i<<" ";
        }
        cout<<endl<<n/2 +1<<endl;
        cout<<n/2<<" "<<n/2 +1<<" ";
        for(int i=n/4+1;i<n/2;i++){
            cout<<i<<" "<<n-i<<" ";
        }
    }

    return 0;
}