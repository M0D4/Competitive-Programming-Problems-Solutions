#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))
  using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
 const int N = 100 + 5;
int a[N][N], n;
 bool valid(int r, int c){
    return ~r && ~c && r < n && c < n;
}
 bool ok(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if(valid(x, y)){
                    if(abs(a[i][j] - a[x][y]) == 1) return 0;
                }
            }
        }
    }
    return 1;
}
 void solve(){
    cin >> n;
    if(n == 2) return cout << "-1\n", void();
    if(n == 3){
        cout << "2 9 7\n";
        cout << "4 6 3\n";
        cout << "1 8 5\n";
        return;
    }
     bool f[n * n + 1];
    clr(f, 0);
    int c = 0, i = 0, j = 0, mn = 1;
    while (c < n * n){
        while (f[mn]) mn++;
        int ele = mn;
        while (i < n && !f[ele] && ele <= n * n){
            a[i][j++] = ele, f[ele] = 1, ele += 2, c++;
            if(j == n) j = 0, i++, ele--;
        }
        if(j == n) j = 0, i++;
    }
     for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
            cout << a[k][l] << " \n"[l + 1 == n];
        }
    }
    cout << endl;
}
 int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
      int tc; cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}