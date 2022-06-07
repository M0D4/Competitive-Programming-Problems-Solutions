#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int n,cnt=0 ; cin>>n;
   string s; cin>>s;
   int freq[128]={0};
   for(int i=0; i<n; i++){
        s[i] = tolower(s[i]);
        if(!freq[s[i]])cnt++;
        freq[s[i]]++;
   }
   if(cnt==26)cout<<"YES";
   else cout<<"NO";
    return 0;
}