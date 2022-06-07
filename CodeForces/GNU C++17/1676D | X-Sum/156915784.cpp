#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
int n, m;
 
 
bool valid(int r, int c){
    return ~r && ~c && r < n && c < m;
}
 
const int N = 200 + 5;
int a[N][N];
ll rightDiagonal[N][N], leftDiagonal[N][N];
 
void calcRightDiagonal(int i, int j){
    ll ans = 0;
    int x = i, y = j;
    while (valid(i, j))
        ans += a[i][j], ++i, ++j;
    i = x, j = y;
    while (valid(i, j))
        rightDiagonal[i][j] = ans, ++i, ++j;
}
 
void calcLeftDiagonal(int i, int j){
    ll ans = 0;
    int x = i, y = j;
    while (valid(i, j))
        ans += a[i][j], --i, ++j;
    i = x, j = y;
    while (valid(i, j))
        leftDiagonal[i][j] = ans, --i, ++j;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TC; cin >> TC;
    while(TC--){
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                rightDiagonal[i][j] = leftDiagonal[i][j] = -1;
            }
        }
        for (int i = 0; i < m; ++i) {
            calcRightDiagonal(0, i);
        }
        for (int i = 1; i < n; ++i) {
            calcRightDiagonal(i, 0);
        }
        for (int i = 0; i < m; ++i) {
            calcLeftDiagonal(n - 1, i);
        }
        for (int i = 0; i < n - 1; ++i) {
            calcLeftDiagonal(i, 0);
        }
        ll mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(rightDiagonal[i][j] == -1) calcRightDiagonal(i, j);
                if(leftDiagonal[i][j] == -1) calcLeftDiagonal(i, j);
                mx = max(mx, rightDiagonal[i][j] + leftDiagonal[i][j] - a[i][j]);
            }
        }
        cout << mx << endl;
    }
    return 0;
}