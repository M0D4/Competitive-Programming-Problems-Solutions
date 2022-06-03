#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;



int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    int a[n][5];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }

    auto ok = [&](int& mid) -> bool{
        set<int> masks;
        for(auto& v: a){
            int mask = 0;
            for(auto& element: v){
                mask <<= 1;
                mask |= (element >= mid);
            }
            masks.insert(mask);
        }
        for(auto&i: masks) for(auto &j: masks) for(auto& k: masks){
                    if((i | j | k) == (1 << 5) - 1) return 1;
        }
        return 0;
    };

    int l = 1, r = 1e9;
    while (l <= r){
        int mid = (l + r) >> 1;
        if(ok(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1;
    return 0;
}