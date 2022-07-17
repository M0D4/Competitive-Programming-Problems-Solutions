#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        string a[n];
        map<string, bool> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]] = 1;
        }
        for (int i = 0; i < n; ++i) {
            bool ok = 0;
            for (int j = 0; j + 1 < a[i].size() && !ok; ++j) {
                ok |= mp.count(a[i].substr(0, j + 1)) && mp.count(a[i].substr(j + 1));
            }
            cout << ok;
        }
        cout << endl;
    }
    return 0;
}