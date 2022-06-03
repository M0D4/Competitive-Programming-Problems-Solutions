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
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)


typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

const int N = 2e5 + 5;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, w; cin >> n >> w;

    ll pfx[N] = {};

    for(int i = 1; i <= n; i++){
        int l, r, p; cin >> l >> r >> p;
        pfx[l + 1] += p;
        pfx[r + 1] -= p;
    }

    for(int i = 1; i < N; i++) pfx[i] += pfx[i - 1];

    cout << (*max_element(pfx + 1, pfx + N) > w ? "No" : "Yes");
    return 0;
}
