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
 
enum dir {
    RIGHT, LEFT, DOWN, UP, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT
};
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<char>> a(n, vector<char>(m));
 
    int startRow, startColumn, endRow, endColumn;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'S') startRow = i, startColumn = j;
            else if (a[i][j] == 'T') endRow = i, endColumn = j;
        }
    }
 
    vector<vector<bool>> pre(n, vector<bool>(m));
 
    for (int i = endColumn; i < m; ++i) {
        if(a[endRow][i] == '*') break;
        pre[endRow][i] = 1;
    }
    for (int i = endColumn; i >= 0; --i) {
        if(a[endRow][i] == '*') break;
        pre[endRow][i] = 1;
    }
    for (int i = endRow; i < n; ++i) {
        if (a[i][endColumn] == '*') break;
        pre[i][endColumn] = 1;
    }
    for (int i = endRow; i >= 0; --i) {
        if (a[i][endColumn] == '*') break;
        pre[i][endColumn] = 1;
    }
 
    auto check = [&](int r, int c){
        for (int i = c; i < m; ++i) {
            if (a[r][i] == '*') break;
            if (pre[r][i]) return true;
        }
        for (int i = c; i >= 0; --i) {
            if (a[r][i] == '*') break;
            if (pre[r][i]) return true;
        }
        for (int i = r; i < n; ++i) {
            if (a[i][c] == '*') break;
            if (pre[i][c]) return true;
        }
        for (int i = r; i >= 0; --i) {
            if (a[i][c] == '*') break;
            if (pre[i][c]) return true;
        }
        return false;
    };
 
    bool ok = 0;
 
    for (int i = startColumn; i < m; ++i) {
        if (a[startRow][i] == '*') break;
        if (check(startRow, i))
            ok = 1;
    }
    for (int i = startColumn; i >= 0; --i) {
        if (a[startRow][i] == '*') break;
        if (check(startRow, i))
            ok = 1;
    }
    for (int i = startRow; i < n; ++i) {
        if (a[i][startColumn] == '*') break;
        if (check(i, startColumn))
            ok = 1;
    }
    for (int i = startRow; i >= 0; --i) {
        if (a[i][startColumn] == '*') break;
        if (check(i, startColumn))
            ok = 1;
    }
    cout << (ok ? "YES" : "NO");
    return 0;
}