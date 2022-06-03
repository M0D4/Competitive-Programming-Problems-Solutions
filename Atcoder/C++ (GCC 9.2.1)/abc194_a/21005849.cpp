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

    int a, b; cin >> a >> b;
    if(a + b >= 15 && b >= 8) cout << 1;
    else if(a + b >= 10 && b >= 3) cout << 2;
    else if(a + b >= 3) cout << 3;
    else cout << 4;
    return 0;
}