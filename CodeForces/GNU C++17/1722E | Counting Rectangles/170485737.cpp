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
 
const int N = 1e3 + 5;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while (TC--) {
        int n, q;
        cin >> n >> q;
 
        vector<vector<ll>> a(N + 1, vector<ll>(N + 1));
 
        for (int i = 0; i < n; ++i) {
            int h, w;
            cin >> h >> w;
            a[h][w] += 1LL * h * w;
        }
 
        auto accuSum2D = [&]() {
            //accumulate each row
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    a[i][j] += a[i][j - 1];
 
            //accumulate each col
            for (int j = 1; j <= N; j++)
                for (int i = 1; i <= N; i++)
                    a[i][j] += a[i - 1][j];
        };
 
        auto sum_range = [&](int i, int j, int k, int l) {
            return a[k][l] - a[k][j - 1] - a[i - 1][l] + a[i - 1][j - 1];
        };
 
        accuSum2D();
 
        while (q--) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            if (hs == hb - 1 || ws == wb - 1){
                cout << "0\n";
                continue;
            }
            cout << sum_range(hs + 1, ws + 1, hb - 1, wb - 1) << endl;
        }
    }
    return 0;
}