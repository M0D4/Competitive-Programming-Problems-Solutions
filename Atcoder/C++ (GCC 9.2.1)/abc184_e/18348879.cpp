#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))



typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

int n, m;

bool ok(int r, int c){
    return ~r && ~c && r < n && c < m;
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    char a[n][m];
    pii st, ed;
    map<char, vector<pii>> mp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];

            if(a[i][j] == 'G') ed = {i, j};
            else if(a[i][j] == 'S') st = {i, j};
            else if(isalpha(a[i][j]))
                mp[a[i][j]].push_back({i, j});
        }
    }

    int dis[n][m]; clr(dis, -1);

    priority_queue<tii, vector<tii>, greater<tii>> q; //dis, r, c

    q.push(make_tuple(0, st.first, st.second));

    while(q.size()){
        int r, c, d; tie(d, r, c) = q.top(); q.pop();

        if(~dis[r][c]) continue;
        dis[r][c] = d;

        if(a[r][c] == 'G') break;

        for(int i = 0; i < 4; i++){
            int x = r + dx[i], y = c + dy[i];
            if(ok(x, y) && a[x][y] != '#' && (dis[x][y] > dis[r][c] + 1 || dis[x][y] == -1)){
                q.push(make_tuple(dis[r][c] + 1, x, y));
            }
        }

        if(isalpha(a[r][c]) && islower(a[r][c]) && mp.count(a[r][c])){
            for(auto &p: mp[a[r][c]]){
                int x = p.first, y = p.second;
                if(dis[x][y] == -1 || dis[x][y] > dis[r][c] + 1){
                    q.push(make_tuple(dis[r][c] + 1, x, y));
                }
            }
            mp.erase(a[r][c]);
        }

    }

    cout << dis[ed.first][ed.second];
    return 0;
}
