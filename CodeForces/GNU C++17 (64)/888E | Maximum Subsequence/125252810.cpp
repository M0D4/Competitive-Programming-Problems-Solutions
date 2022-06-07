#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n, m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    if(n == 1){
        return cout << a[0] % m, 0;
    }
    int mx = 0;
    vector<int> part;
    for (int i = 1; i < (1 << (n / 2)); ++i) {
        int sum = 0;
        for (int j = 0; j < n / 2; ++j) {
            if((i >> j) & 1){
                sum += a[j];
                sum %= m;
            }
        }
        part.push_back(sum);
        mx = max(mx, sum);
    }
    sort(all(part));
 
    for (int i = 1; i < (1 << ((n + 1) / 2)); ++i) {
        int sum = 0;
        for (int j = 0; j < (n + 1) / 2; ++j) {
            if((i >> j) & 1){
                sum += a[j + n / 2];
                sum %= m;
            }
        }
        int want = (m - sum) % m;
        if(want == 0) want = m;
        want--;
        auto it = upper_bound(all(part), want);
        if(it != part.begin()) it--;
        mx = max(mx, (sum + *it) % m);
        mx = max(mx, sum);
    }
    cout << mx;
    return 0;
}