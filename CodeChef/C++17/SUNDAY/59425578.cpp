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

    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int f[31] = {};
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            f[x] = 1;
        }
        int cnt = 0, day = 1;
        for (int i = 1; i <= 30; ++i) {
            cnt += (f[i] || day == 6 || day == 7);
            day++;
            if(day > 7) day = 1;
        }
        cout << cnt << endl;
    }
    return 0;
}