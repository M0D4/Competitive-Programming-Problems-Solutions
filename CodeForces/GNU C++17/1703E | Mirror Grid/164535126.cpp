#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
vector<vector<pair<char, pair<int, int>>>> rotate90(vector<vector<pair<char, pair<int, int>>>> a, int n){
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            char temp = a[i][j].first;
            a[i][j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
            a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
            a[j][n - 1 - i].first = temp;
        }
    }
    return a;
}
 
void printV(vector<vector<pair<char, pair<int, int>>>>& a){
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "[" << a[i][j].second.first << " " << a[i][j].second.second << "] ";
        }
        cout << endl;
    }
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        vector<vector<pair<char, pair<int, int>>>> a(n, vector<pair<char, pair<int, int>>>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j].first;
                a[i][j].second = {i, j};
            }
        }
 
        auto v1 = a;
        auto v2 = rotate90(v1, n);
        auto v3 = rotate90(v2, n);
        auto v4 = rotate90(v3, n);
 
        int cnt = 0;
        bool vis[n][n] = {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j]) continue;
                int f[2] = {};
                f[v1[i][j].first - '0']++;
                f[v2[i][j].first - '0']++;
                f[v3[i][j].first - '0']++;
                f[v4[i][j].first - '0']++;
                cnt += min(f[0], f[1]);
                vis[v1[i][j].second.first][v1[i][j].second.second] = 1;
                vis[v2[i][j].second.first][v2[i][j].second.second] = 1;
                vis[v3[i][j].second.first][v3[i][j].second.second] = 1;
                vis[v4[i][j].second.first][v4[i][j].second.second] = 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}