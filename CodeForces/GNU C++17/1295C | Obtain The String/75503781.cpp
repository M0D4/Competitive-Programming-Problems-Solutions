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
#define numOfDigits(n)  ((n)? (ll)(log10(n)+1) : 1)
#define mem(x, val)    memset(x, val, sizeof(x))
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
  int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int T; cin>>T;
    while(T--){
        string s, t; cin>>s>>t;
        int n = s.size(), m = t.size();
        map<char, bool> mp;
        for(int i =0; i<n; i++)
            mp[s[i]] = 1;
        bool cant = 0;
        for(int i = 0; i<m; i++)
            if(!mp[t[i]]){
                cant = 1;
                break;
            }
        if(cant){
            cout<<"-1\n";
            continue;
        }
        map<char, set<int>> index;
        for(int i =0; i<n; i++){
            index[s[i]].insert(i);
        }
        vector<int> res(m);
        for(int i = 0; i<m; i++){
            if(!i) res[i] = *index[t[i]].begin();
            else{
                auto it = index[t[i]].upper_bound(res[i-1]);
                if(it==index[t[i]].end())res[i]=*index[t[i]].begin();
                else res[i] = *it;
            }
        }
        int cost = 1;
        for(int i = 1; i<m; i++){
            if(res[i]<=res[i-1])cost++;
        }
        cout<<cost<<endl;
    }
    return 0;
}
    