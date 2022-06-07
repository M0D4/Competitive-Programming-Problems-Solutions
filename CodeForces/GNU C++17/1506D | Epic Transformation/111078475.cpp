#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        priority_queue<int> v;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
        }
 
        for(auto& i: mp)
            v.push(i.second);
 
        while (v.size() > 1){
            int p = v.top(); v.pop();
            int q = v.top(); v.pop();
            --p, --q;
            if(p) v.push(p);
            if(q) v.push(q);
        }
        if(v.empty()) v.push(0);
        cout << v.top() << endl;
    }
    return 0;
}