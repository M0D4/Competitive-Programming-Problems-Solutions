#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while(tc--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
 
        vector<int> x(26);
        for (int i = 0; i < n; ++i) {
            x[s[i] - 'a']++;
        }
        int l = 1, r = n / k;
        while (l <= r){
            int mid = (l + r) >> 1;
            bool ok = 1;
            auto f = x;
            for (int i = 0; i < k && ok; ++i) {
                int cnt = 0, odd = 0;
                for (int j = 0; j < 26 && cnt < mid; ++j) {
                    int need = min(f[j], mid - cnt);
                    if(need & 1 && (f[j] & 1 ^ 1)) continue;
                    if((need & 1) && (mid & 1) && odd == 0) cnt += need, f[j] -= need, odd = 1;
                    else cnt += need - (need & 1), f[j] -= need - (need & 1);
                }
                for (int j = 0; j < 26 && cnt < mid; ++j) {
                    int need = min(f[j], mid - cnt);
                    if((need & 1) && (mid & 1) && odd == 0) cnt += need, f[j] -= need, odd = 1;
                    else cnt += need - (need & 1), f[j] -= need - (need & 1);
                }
                if(cnt < mid) ok = 0;
            }
            if(ok) l = mid + 1;
            else r = mid - 1;
        }
        cout << l - 1 << endl;
    }
    return 0;
}