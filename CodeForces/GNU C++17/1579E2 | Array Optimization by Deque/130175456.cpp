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
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ordered_set<int> s;
        ll inversions = 0;
        for (int i = 0; i < n; ++i){
            int order = s.order_of_key(a[i]);
            int upper = s.order_of_key(a[i] + 1);
            int mn = min(order, (int)s.size() - upper);
            inversions += mn;
            s.insert(a[i]);
        }
        cout << inversions << endl;
    }
    return 0;
}
 