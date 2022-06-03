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
        ll w, x, y, z; cin >> w >> x >> y >> z;
        w += y * z;
        if(w > x) cout << "overflow\n";
        else if(w == x) cout << "filled\n";
        else cout << "unfilled\n";
    }
    return 0;
}