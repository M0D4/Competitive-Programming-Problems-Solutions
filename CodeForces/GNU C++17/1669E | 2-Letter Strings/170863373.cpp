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
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (char j = 'a'; j <= 'k'; ++j) {
                if (j != a[i][0]) {
                    if (mp.count(string(1, j) + a[i][1]))
                        ans += mp[string(1, j) + a[i][1]];
                }
                if (j != a[i][1]) {
                    if (mp.count(string(1, a[i][0]) + j))
                      ans += mp[string(1, a[i][0]) + j];
                }
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}