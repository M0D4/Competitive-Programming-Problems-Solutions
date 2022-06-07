#include "bits/stdc++.h"
 
 
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-O2")
 
 
using namespace std;
 
//#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, val)    memset(x, val, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
 
using namespace __gnu_pbds;
 
 
template<
        typename Key,
        typename Mapped,
        typename Cmp_Fn = std::less<Key>,
        typename Tag = rb_tree_tag,
        template<
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_>
        class Node_Update = null_node_update,
        typename Allocator = std::allocator<char> >
class tree;
 
 
using ordered_set = __gnu_pbds::tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>;
 
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n, t; cin >> n >> t;
 
    ordered_set s;
    int mp[n + 3];
    clr(mp, -1);
 
    while (t--){
        int k; cin >> k;
        int l = 1, r = n;
        while (l <= r){
            int mid = (l + r) >> 1;
            int ones, zeros;
            if(~mp[mid]) ones = mp[mid] + s.order_of_key(mid + 1);
            else{
                cout << "? 1 " << mid << endl << flush;
                int x; cin >> x;
                mp[mid] = x - s.order_of_key(mid);
                ones = x;
            }
            zeros = mid - ones;
            if(zeros >= k) r = mid - 1;
            else l = mid + 1;
        }
        cout << "! " << r + 1 << endl << flush;
        s.insert(r + 1);
    }
    return 0;
}