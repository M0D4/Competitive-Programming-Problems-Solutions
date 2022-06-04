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
 const int N  = 2e5 + 10;
 class FenwickTree {
private:
    vector<int> ft;
public:
    int LSOne(int x){
        return (x & (-x));
    }
    FenwickTree(int n) {
        ft.assign(n + 2, 0);
    }
    int rsq(int b) {
        int sum = 0;//overflow?
        for( ; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
     int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
     void update(int k, int v) { // int v overflow?
        for (; k < ft.size(); k += LSOne(k)) ft[k] += v;
    }
};
 map<pair<int, int>, int> mp;
  int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int n, t; cin >> n >> t;
     FenwickTree ft(n + 3);
     while (t--){
        int k; cin >> k;
        int l = 1, r = n;
        while (l < r){
            int mid = (l + r) >> 1;
            int ones = ft.rsq(l, mid), zeros = 0;
             if(mp.count({l, mid})) ones += mp[{l, mid}];
            else{
                cout << "? " << l << " " << mid << endl << flush;
                int sum; cin >> sum;
                mp[{l, mid}] = sum - ones;
                ones = sum;
            }
             zeros = mid - l + 1 - ones;
            if(zeros >= k) r = mid;
            else k -= zeros, l = mid + 1;
        }
        cout << "! " << l << endl << flush;
        ft.update(l, 1);
    }
    return 0;
}