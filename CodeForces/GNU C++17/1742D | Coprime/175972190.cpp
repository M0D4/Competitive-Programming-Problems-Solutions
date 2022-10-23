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
 
const int N = 1e3 + 5;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a[n];
        vector<int> f[N] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]].push_back(i + 1);
        }
        int mx = -1;
        for (int i = 1; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                if (__gcd(i, j) != 1) continue;
                if (f[i].empty() || f[j].empty()) continue;
                mx = max(mx, f[i].back() + f[j].back());
            }
        }
        cout << mx << endl;
    }
    return 0;
}