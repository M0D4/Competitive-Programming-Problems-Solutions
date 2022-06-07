#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(all(b));
 
        vector<vector<int>> ans;
        auto shift = [&](int start){
            int idx = 0;
            for (int i = start; i < n; ++i) {
                if(a[i] == b[start]){
                    idx = i;
                    break;
                }
            }
            if(idx - start) ans.push_back({start + 1, n, idx - start});
            vector<int> c = a;
            for (int i = idx, j = start; j < n; ++i, ++j) {
                if(i == n) i = start;
                c[j] = a[i];
            }
            a = c;
        };
 
        for (int i = 0; i < n - 1; ++i) {
            shift(i);
        }
 
        cout << ans.size() << endl;
        for(auto &v: ans){
            for(auto& i: v){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
 