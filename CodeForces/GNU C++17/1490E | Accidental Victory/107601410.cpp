#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n];
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]].push_back(i);
        }
        sort(a, a + n);
        int l = 0, r = n - 1, ans = n;
        while (l <= r){
            int mid = (l + r) >> 1;
            ll sum = a[mid];
            for(int i = 0; i < mid; i++)
                sum += a[i];
            bool ok = 1;
            for(int i = mid + 1; i < n; i++){
                if(sum < a[i]){
                    ok = 0;
                    break;
                }
                sum += a[i];
            }
            if(ok) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        map<int, bool> vis;
        vector<int> pos;
        for (int i = ans; i < n; ++i) {
            if(vis[a[i]]) continue;
            vis[a[i]] = 1;
            for(auto& j: mp[a[i]]){
                pos.push_back(j);
            }
        }
        sort(all(pos));
        cout << pos.size() << endl;
        for(auto& i: pos)
            cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}