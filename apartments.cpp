#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main()
{   int peep_num, apa_num, diff;
    cin>>peep_num>>apa_num>>diff;
    vector<int> des_size(peep_num);
    vector<int> apa_size(apa_num);
    for(int i = 0;i<peep_num;i++){
        cin>>des_size[i];
    }
    for(int i = 0;i<apa_num;i++){
        cin>>apa_size[i];
    }
    sort(des_size.begin(), des_size.end());
    sort(apa_size.begin(), apa_size.end());
    int i =0;int j=0;
    int count=0;
    while(i<peep_num && j<apa_num)
    {   if(abs(des_size[i] - apa_size[j]) <= diff ){
            count++;
            i++;j++;
        }
        else if(des_size[i] > apa_size[j]){
            j++;
        }
        else{
            i++;
        }

    }

    cout<<count;

    return 0;
}