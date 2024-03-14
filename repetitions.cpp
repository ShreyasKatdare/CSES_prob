#include <bits/stdc++.h>
using namespace std;
int main()
{   int n = 1e6 +1;
    char s[n];
    cin.getline(s, n);
    // cout<<"hello\n";
    if(s[0]=='\0'){
        cout<<0;
        return 0;
    }
    
    int c=1;
    int maxx = c;
    for(int i=1; s[i]!='\0';i++){
        // cout<<"hello\n";
        if(s[i] == s[i-1]){
            c++;
        }
        else{
            maxx = max(maxx, c);
            c = 1;
        }
    }
    maxx = max(maxx, c);
    cout<<maxx;


    return 0;
}