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
            vector<int> a(n);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            vector<int> b;
            ll rem = (1LL << 30) - 1;
            vector<bool> vis(n);
            for (int i = 29; i >= 0; --i) {
                ll v = 0, idx = -1;
                for (int j = 0; j < n; ++j) {
                    if (vis[j]) continue;
                    if ((rem & a[j]) > v)
                        v = rem & a[j], idx = j;
                }
                if (idx == -1) break;
                vis[idx] = 1;
                b.push_back(a[idx]);
                rem &= ~v;
            }
            for (int i = 0; i < n; ++i) {
                if (!vis[i])
                    b.push_back(a[i]);
            }
            for (int i = 0; i < n; ++i) {
                cout << b[i] << " ";
            }
            cout << endl;
        }
        return 0;
    }