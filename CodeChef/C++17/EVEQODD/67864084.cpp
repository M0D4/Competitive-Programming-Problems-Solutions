#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

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
        int n; cin >> n;
        int a[n * 2];
        int even = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        for (int i = 0; i < n * 2; ++i) {
            cin >> a[i];
            int cnt = __builtin_ctz(a[i]);
            if(cnt == 0) q.push({1, 1});
            else q.push({cnt, 0}), even++;
        }
        ll ans = 0;
        while (even < n){
            int x, cnt;
            tie(cnt, x) = q.top();
            q.pop();
            if(x == 0) continue;
            ans += cnt;
            even++;
        }
        while (even > n){
            int x, cnt;
            tie(cnt, x) = q.top();
            q.pop();
            if(x == 1) continue;
            ans += cnt;
            even--;
        }
        cout << ans << endl;
    }
    return 0;
}