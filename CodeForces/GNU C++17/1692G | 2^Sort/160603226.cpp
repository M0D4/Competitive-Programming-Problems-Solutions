#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n, k; cin >> n >> k;
        int a[n], pre[n + 3] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            pre[i + 1] = pre[i] + (a[i] * 2LL <= a[i - 1]);
        }
        int cnt = 0;
        for (int i = 1; i + k <= n; ++i) {
            int bad = pre[i + k] - pre[i];
            if(!bad) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}