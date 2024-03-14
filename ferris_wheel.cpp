#include <bits/stdc++.h>
using namespace std;

int main()
{   int num_child, max_weight;
    cin>>num_child>>max_weight;
    vector<int> weights(num_child);
    for(int i=0;i<num_child;i++){
        cin>>weights[i];
    }
    int count=0, i=0;
    sort(weights.begin(), weights.end());
    int j = num_child-1;
    while(i<=j)
    {   if(i==j){
            count++;break;
        }
        if(weights[i]+weights[j]<= max_weight){
            count++;
            i++;
            j--;
        }
        else{
            count++;
            j--;
        }
    }

    cout<<count;
    return 0;
}