#include <bits/stdc++.h>
#include <ext/numeric>
 using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define MOD 1000000007
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
 int freq[26];
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    string s; cin>>s;
    int n = s.size();
    for(int i = 0; i<n; i++)
        freq[s[i]-'a']++;
    vector<char> v;
    for(int i =0; i<26; i++){
        if(freq[i]&1)
            v.pb(i+'a');
    }
    string ans = "";
    if(v.empty()){
        for(int i =0; i<26; i++)
            if(freq[i]){
                ans += string(freq[i]/2, i+'a');
            }
        cout<<ans;
        reverse(all(ans));
        cout<<ans;
        return 0;
    }
    for(int i =0, j = v.size()-1; i<(int)v.size()/2; i++, j--){
        freq[v[j]-'a']--;
        v[j] = v[i];
        freq[v[j]-'a']++;
    }
    char c = ' ';
    for(int i =0; i<26; i++){
        if(freq[i]&1)c = i+'a';
        if(freq[i]){
            ans += string(freq[i]/2, i+'a');
        }
    }
        cout<<ans;
        if(c!=' ')cout<<c;
        reverse(all(ans));
        cout<<ans;
 return 0;
}