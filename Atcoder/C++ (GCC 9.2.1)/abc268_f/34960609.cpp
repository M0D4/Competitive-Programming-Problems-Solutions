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

    int n;
    cin >> n;

    vector<string> a(n);

    int x[n], y[n] = {};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x[i] = count(all(a[i]), 'X');
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] == 'X') continue;
            y[i] += a[i][j] - '0';
        }
    }
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) {
        idx[i] = i;
    }
    sort(all(idx), [&](int& i, int& j){
       return (1LL * x[i] * y[j] > 1LL * x[j] * y[i]);
    });

    ll cnt = 0;
    ll xCnt = 0;
    for (int i = 0; i < n; ++i) {
        string s = a[idx[i]];
        for (int j = 0; j < s.size(); ++j) {
            if(s[j] == 'X') xCnt++;
            else{
                cnt += xCnt * (s[j] - '0');
            }
        }
    }
    cout << cnt;
    return 0;
}
