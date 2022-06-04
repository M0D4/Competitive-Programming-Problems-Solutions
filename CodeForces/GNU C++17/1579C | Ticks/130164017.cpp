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
 const int N = 20;
bool vis[N][N];
char a[N][N];
 int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        int n, m, k; cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        }
        auto valid = [&](int r, int c){
            return ~r && ~c && r < n && c < m;
        };
         auto go = [&](int r, int c){
            int c2 = c, d = 0;
            int rCopy = r, cCopy = c;
            int visBefore = 0;
            while (valid(r, c) && valid(r, c2) && a[r][c] == '*' && a[r][c2] == '*'){
                visBefore += vis[r][c] + (c != c2 && vis[r][c2]);
                r--;
                c2--, c++;
                d++;
            }
            if(d > k){
                c2 = c = cCopy;
                r = rCopy;
                while (valid(r, c) && valid(r, c2) && a[r][c] == '*' && a[r][c2] == '*'){
                    vis[r][c] = vis[r][c2] = 1;
                    r--;
                    c2--, c++;
                }
                return true;
            }
            return (visBefore == 2 * d - 1);
        };
         bool ok = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == '*'){
                    int d = go(i, j);
                }
            }
        }
        for (int i = 0; i < n && ok; ++i) {
            for (int j = 0; j < m && ok; ++j) {
                if(a[i][j] == '*' && vis[i][j] == 0) ok = 0;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
 