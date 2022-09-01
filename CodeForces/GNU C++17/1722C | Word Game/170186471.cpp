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
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        map<string, int> mp;
        string a[3][n];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                string s; cin >> s;
                a[i][j] = s;
                mp[s]++;
            }
        }
        int ans[3] = {};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mp[a[i][j]] == 1) ans[i] += 3;
                else if (mp[a[i][j]] == 2) ans[i]++;
            }
        }
        for (int i = 0; i < 3; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}