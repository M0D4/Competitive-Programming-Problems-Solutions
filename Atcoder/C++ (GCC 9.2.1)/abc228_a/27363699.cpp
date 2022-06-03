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

    int s, t, x; cin >> s >> t >> x;
    s *= 60, t *= 60, x *= 60;
    x += 30;
    if(s < t) cout << (x >= s && x <= t ? "Yes" : "No");
    else cout << (x > t && x < s ? "No" : "Yes");
    return 0;
}