#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;


///Intermediate Overflow!!! (1 << i), x * y, 2 * x

const double eps = 1e-8;

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    double a[n], b[n];
    int len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        len += a[i];
    }
    double l = 0, r = 1e18, ans = 0;
    while (islessequal(l, r)){
        double mid = (l + r) / 2;
        double cur = mid, dis1 = 0, dis2 = 0;
        for (int i = 0; i < n && isgreater(cur, 0.0); ++i) {
            if(isgreaterequal(cur, a[i] / b[i])){
                dis1 += a[i];
                cur -= a[i] / b[i];
            }else{
                dis1 += cur * b[i];
                cur = 0;
            }
        }
        cur = mid;
        for (int i = n - 1; i >= 0 && isgreater(cur, 0.0); --i) {
            if(isgreaterequal(cur, a[i] / b[i])){
                dis2 += a[i];
                cur -= a[i] / b[i];
            }else{
                dis2 += cur * b[i];
                cur = 0;
            }
        }
        dis2 = len - dis2;
        if(isgreaterequal(dis2, dis1)) l = mid + eps, ans = dis2;
        else r = mid - eps;
    }
    cout << fixed << setprecision(9);
    cout << ans;
    return 0;
}

