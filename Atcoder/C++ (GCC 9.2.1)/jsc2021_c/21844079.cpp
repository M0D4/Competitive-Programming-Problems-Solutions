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
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;

const int N = 2e5 + 5;
int f[N];

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);

    int a, b; cin >> a >> b;
    int mx = 1;
    for (int i = 1; i <= b; ++i) {
        int x = 0;
        for (int j = i; j <= b; j += i) {
            if(j >= a) x++;
        }
        if(x > 1)
            mx = i;
    }

    cout << mx;
    return 0;
}