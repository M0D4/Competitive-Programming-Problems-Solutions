#include "bits/stdc++.h"
 #pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 1e5 + 5;
int n;
int a[100];
 int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
 bool ok(int &r, int &c){
//    if(r < 1 || r > n || c < 1) return 0;
     if(r < 1) r = 1;
    else if(r > n) r = n;
     if(c < 1) c = 1;
    else if(c > a[r - 1]) c = a[r - 1] + 1;
       return 1;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
     int dis[n + 5][N];
    clr(dis, -1);
     int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
     queue<pair<int, int>> q;
    q.push({sx, sy});
    dis[sx][sy] = 0;
     while(q.size()){
        int r = q.front().first, c = q.front().second;
        q.pop();
         if(r == ex && c == ey) break;
         for(int i = 0; i < 4; i++){
            int x = r + dx[i], y = c + dy[i];
            if(ok(x, y) && dis[x][y] == -1){
                dis[x][y] = dis[r][c] + 1;
                q.push({x, y});
            }
        }
    }
     cout << dis[ex][ey];
    return 0;
}