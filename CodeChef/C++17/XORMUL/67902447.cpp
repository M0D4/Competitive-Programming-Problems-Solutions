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
        ll n, a, b; cin >> n >> a >> b;

        if(a > b) swap(a, b);

        ll ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int b1 = ((a >> i) & 1);
            int b2 = ((b >> i) & 1);

            if (b1 == b2 && b1 == 1) continue;

            ll c  = ans | (1 << i);
            if((c ^ a) * (c ^ b) > (ans ^ a) * (ans ^ b))
                ans |= (1 << i);
        }
        cout << ans << endl;
       
    }
    return 0;
}

 