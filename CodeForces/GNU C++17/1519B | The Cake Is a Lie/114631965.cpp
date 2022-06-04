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
  int n, m, k;
 bool valid(int r, int c){
    return ~r && ~c && r < n && c < m;
}
 const int N = 1e2 + 2, M = 1e4 + 1;
 short vid;
short vis[N][N][M];
 int go(int r, int c, int rem){
    if(r == n - 1 && c == m - 1) return rem == 0;
    if(vis[r][c][rem] == vid) return 0;
     vis[r][c][rem] = vid;
     if(valid(r + 1, c) && go(r + 1, c, rem - c - 1)) return 1;
    if(valid(r, c + 1) && go(r, c + 1, rem - r - 1)) return 1;
     return 0;
}
 int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while(t--){
        ++vid;
        cin >> n >> m >> k;
        cout << (go(0, 0, k) ? "YES" : "NO") << endl;
    }
    return 0;
}