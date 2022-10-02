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
 
    int n, K;
    cin >> n >> K;
 
    vector<vector<int>> a(n, vector<int> (K));
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> a[i][j];
        }
    }
 
    map<vector<int>, int> mp;
 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> third;
            for (int k = 0; k < K; ++k) {
                if (a[i][k] == a[j][k]) third.push_back(a[i][k]);
                else third.push_back(3 - a[i][k] - a[j][k]);
            }
            mp[third]++;
        }
    }
 
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll cnt = mp[a[i]];
        ans += cnt * (cnt - 1) >> 1;
    }
    cout << ans;
    return 0;
}