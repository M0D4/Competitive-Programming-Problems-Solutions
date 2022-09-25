#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
const double eps = 1e-9;
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cout << fixed << setprecision(7);
 
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int a[n], t[n];
        ll tSum = 0, xSum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            xSum += a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
            tSum += t[i];
        }
        auto f = [&](double& mid){
            double mx = -1e9;
            for (int i = 0; i < n; ++i) {
                 if (isgreater(t[i] + abs(a[i] - mid), mx))
                     mx = (t[i] + abs(a[i] - mid));
            }
            return mx;
        };
 
        auto ternary_search = [&](double l, double r) {
            for (int i = 0; i < 300; ++i) {
                double m1 = l + (r - l) / 3;
                double m2 = r - (r - l) / 3;
                double f1 = f(m1);
                double f2 = f(m2);
 
                if (isless(f1, f2))
                    r = m2;
                else
                    l = m1;
            }
            return l;
        };
 
        cout << ternary_search(0, 1e16) << endl;
    }
    return 0;
}