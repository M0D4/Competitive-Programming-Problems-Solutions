#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
#define Unique(x)       x.erase(unique(all(x)), x.end())
 using ll = long long;
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
     int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<pair<int, int>> ops;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]){
                    ops.push_back({i, j});
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (b[i] > b[j]){
                    ops.push_back({i, j});
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                }
            }
        }
         if (ops.size() <= 1e4 && is_sorted(all(a)) && is_sorted(all(b))){
            cout << ops.size() << endl;
            for(auto& p: ops){
                int x = p.first, y = p.second;
                cout << x + 1 << " " << y + 1 << endl;
            }
            cout << endl;
        }else{
            cout << "-1\n\n";
        }
    }
    return 0;
}