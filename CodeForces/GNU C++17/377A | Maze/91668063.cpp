#include "bits/stdc++.h"
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
 int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
 const int N = 505;
 int n, m, k, want, now;
 char a[N][N];
bool vis[N][N];
 bool ok(int r, int c){
    return ~r && ~c && r < n && c < m;
}
 void dfs(int r, int c){
     if(vis[r][c] || a[r][c] != '.') return;
    if(now == want) return;
     vis[r][c] = 1;
    now++;
    for(int i = 0; i < 4; i++){
        int x = r + dx[i], y = c + dy[i];
        if(ok(x, y) && a[x][y] == '.')
            dfs(x, y);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n >> m >> k;
     int free = 0, r = -1, c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == '.'){
                free++;
                if(~r) continue;
                r = i, c = j;
            }
        }
    }
    want = free - k;
    dfs(r, c);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (vis[i][j] || a[i][j] == '#' ? a[i][j] : 'X');
        }
        cout << endl;
    }
    return 0;
}