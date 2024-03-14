#include <bits/stdc++.h>
using namespace std;
int main()
{   int t;
    cin>>t;
    int num[t];
    int mod = int(1e9 + 7);
    int maxx = -1;
    for(int i=0;i<t;i++){
        cin>>num[i];
        if(num[i]>maxx) maxx=num[i];
    }

    int v[maxx+1];
    int ans[maxx+1];
    int v_sum = 2;
    v[0] = 1;
    v[1] = 1;
    ans[1] = 2;
    ans[0] = 1;
    int ans_sum = 2;
    int summ = 1;
    int p[maxx+1];
    p[0] = 1;
    p[1] = 4;
    int sum_p = 5;

    for(int i = 2;i<=maxx;i++){
        v[i] = (v_sum)%mod;
        
        ans[i] = (1+ans_sum+sum_p)%mod;

        for(int xx=0;xx<=i;xx++){
            if(xx==0)
                sum_p = (sum_p+(v[xx]*ans[i-xx])%mod)%mod;
            else
               sum_p = (sum_p+(2*v[xx]*ans[i-xx])%mod)%mod; 
        }
        ans_sum = (ans_sum + ans[i])%mod;
        v_sum = (v_sum + v_sum)%mod;
    }
    for(int i=0;i<t;i++){
        cout<<ans[num[i]]<<endl;
    }


    return 0;
}