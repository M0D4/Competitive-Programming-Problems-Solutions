#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

ll getSum(ll x){
    return x * (x + 1) >> 1LL;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        sum += getSum(y) - getSum(x - 1);
    }
    cout << sum;
    return 0;
}
