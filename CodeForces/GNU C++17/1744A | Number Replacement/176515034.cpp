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
        int n;
        cin >> n;
        int a[n];
        vector<int> b[51];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[a[i]].push_back(i);
        }
        string s;
        cin >> s;
 
        bool ok = 1;
        vector<char> to(n, '?');
        for (int i = 0; i < n && ok; ++i) {
            char c = s[i];
            int code = a[i];
            if (to[i] != '?' && to[i] != c) ok = 0;
            for (auto& x: b[code])
                to[x] = c;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}