#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
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
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
         a[i] = {x, y, i};
    }
    sort(all(a));
    int mnA = a[0][2], vA = a[0][0];
    sort(all(a), [](vector<int> &a, vector<int> &b){
       return a[1] < b[1];
    });
    int mnB = a[0][2], vB = a[0][1];
    if(mnA != mnB)
        return cout << max(vA, vB), 0;

    cout << min(max(vA, a[1][1]), vA + vB);
    return 0;
}			