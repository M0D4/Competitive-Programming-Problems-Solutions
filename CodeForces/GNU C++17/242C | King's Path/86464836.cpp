#include <bits/stdc++.h>
 using namespace std;
 #define all(v)   v.begin(), v.end()
#define pb       push_back
#define sz(x)    (int) (x.size())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
const int N = 1e9;
bool ok(int r, int c){
    return r > 0 && r <= N && c > 0 && c <= N;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    int n; cin >> n;
    map<pair<int, int>, bool> allowed;
    for(int i = 0; i < n; i++){
        int r, a, b; cin >> r >> a >> b;
        for(int col = a; col <= b; col++)
            allowed[{r, col}] = 1;
    }
    map<pair<int, int>, int> dis;
    dis[{x0, y0}] = 0;
    queue<pair<int, int>> q;
    q.push({x0, y0});
    while(!q.empty()){
        int r = q.front().first, c = q.front().second, d = dis[{r, c}];
        q.pop();
        if(r == x1 && c == y1) break;
        for(int i = 0; i < 8; i++){
            int x = r + dx[i], y = c + dy[i];
            if(allowed.count({x, y}) && !dis.count({x, y})){
                q.push({x, y});
                dis[{x, y}] = d + 1;
            }
        }
    }
    cout << (dis.count({x1, y1}) ? dis[{x1, y1}] : -1);
    return 0;
}