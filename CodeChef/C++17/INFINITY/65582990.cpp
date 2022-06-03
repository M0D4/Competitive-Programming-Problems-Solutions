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
        ll n; cin >> n;
        ll cnt = (n - 1) / 5;
        ll step = 1 + cnt * 5;
        cnt *= 2;
        n -= step;
        if(n >= 3) n -= 3, cnt++, step += 3;
        if(n >= 2) n -= 2, cnt++, step += 2;
        if(n >= 1) n -= 1, cnt++, step += 1;
        //debug(n);
        cout << cnt << endl;
    }
    return 0;
}