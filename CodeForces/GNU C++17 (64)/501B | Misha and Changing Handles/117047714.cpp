#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n; cin >> n;
    set<string> used;
    map<string, string> mp;
    while(n--){
        string a, b; cin >> a >> b;
        bool found = 0;
        for(auto &it: mp){
            if(it.second == a){
                found = 1;
                if(!used.count(b)) it.second = b;
                break;
            }
        }
        if(!found && !used.count(b)) mp[a] = b;
        used.insert({a, b});
    }
    cout << mp.size() << endl;
    for(auto &i: mp) cout << i.first << " " << i.second << endl;
    return 0;
}