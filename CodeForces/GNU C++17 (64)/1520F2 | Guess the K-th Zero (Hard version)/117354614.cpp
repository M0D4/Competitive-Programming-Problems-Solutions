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
 map<int, int> mp;
  int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int n, t; cin >> n >> t;
    while (t--){
        int k; cin >> k;
        int l = 1, r = n;
        while (l <= r){
            int mid = (l + r) >> 1;
            int sum = 0, zeros = 0;
             if(mp.count(mid)) zeros = mp[mid];
            else{
                cout << "? " << 1 << " " << mid << endl << flush;
                cin >> sum;
                zeros = mp[mid] = mid - sum;
            }
             if(k <= zeros) r = mid - 1;
            else l = mid + 1;
        }
         cout << "! " << r + 1 << endl << flush;
         for(auto it = mp.lower_bound(r + 1); it != mp.end(); ++it){
            --it->second;
        }
    }
    return 0;
}