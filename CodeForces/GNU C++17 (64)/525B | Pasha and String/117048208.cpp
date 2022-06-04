#include <bits/stdc++.h>
 using namespace std;
 int main()
{
    string s; cin>>s;
    s = " "+s;
    int n = s.size();
    int pre[n+3] = {0};
    int m; cin>>m;
    for(int i=0; i<m; i++){
        int a; cin>>a;
        pre[a]++;
        pre[n-a+1]--;
    }
    for(int i=1; i<n+2; i++)
        pre[i]+=pre[i-1];
    for(int i=1; i<=n/2; i++){
        if(pre[i]%2!=0)
            swap(s[i], s[n-i]);
    }
    cout<<s.substr(1, n-1);
    return 0;
}