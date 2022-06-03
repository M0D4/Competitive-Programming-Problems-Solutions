#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

int dx[] = {0, 1};
int dy[] = {1, 0};


int n, m;
bool valid(int r, int c){
    return ~r && ~c && r < n && c < m;
}

const int N = 100 + 5;
char a[N][N];
int dp[N][N];

int go(int r, int c){

    int& ret = dp[r][c];
    if(~ret) return ret;

    ret = 0;
    if(valid(r, c + 1) && a[r][c + 1] != '#')
        ret = 1 + go(r, c + 1);
    if(valid(r + 1, c) && a[r + 1][c] != '#')
        ret = max(ret, 1 + go(r + 1, c));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    clr(dp, -1);
    cout << go(0, 0) + 1;
    return 0;
}