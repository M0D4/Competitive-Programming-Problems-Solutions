#include "bits/stdc++.h"
  #pragma GCC optimize("-Ofast")
#pragma GCC optimize("-O2")
  using namespace std;
 #define endl            "\n"
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(x.begin(), x.end()), x.end())
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
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
        int a[n], b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int greater = 0, less = 0;
        vector<pii> vGreater, vLess;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if(a[i] < b[i]) vLess.push_back({i, b[i] - a[i]}), less += b[i] - a[i];
            if(a[i] > b[i]) vGreater.push_back({i, a[i] - b[i]}), greater += a[i] - b[i];
        }
        if(less != greater){
            cout << "-1\n";
            continue;
        }
        int i = 0, j = 0;
        vector<pii> seq;
        while (greater){
            while (vGreater[i].second == 0) ++i;
            while (vLess[j].second == 0) ++j;
             while (vGreater[i].second && vLess[j].second){
                seq.push_back({vGreater[i].first, vLess[j].first});
                vGreater[i].second--;
                vLess[j].second--;
                greater--;
            }
        }
        cout << seq.size() << endl;
        for(auto p: seq){
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
    }
    return 0;
}