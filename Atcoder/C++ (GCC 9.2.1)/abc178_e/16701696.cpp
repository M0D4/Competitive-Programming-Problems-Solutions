#include "bits/stdc++.h"

using namespace std;

#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    int mxp = INT_MIN, mnn = INT_MAX, mnp = mnn, mxn = mxp;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        mxp = max(mxp, x + y);
        mnp = min(mnp, x + y);
        mxn = max(mxn, x - y);
        mnn = min(mnn, x - y);
    }
    cout << max(mxp - mnp, abs(mxn - mnn));
    return 0;
}
