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
using pii = pair<int, ll>;
using tii = tuple<int, int, int>;

const int N = 22;

ll n, a[N];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll mn = 9e18;
    for (int i = 0; i < (1 << n); ++i) {
        ll OR = 0, ans = 0;
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                OR |= a[j];
                ans ^= OR;
                OR = 0;
            }else OR |= a[j];
        }
        ans ^= OR;
        mn = min(mn, ans);
    }
    cout << mn;
    return 0;
}