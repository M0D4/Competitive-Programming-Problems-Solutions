#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
  using namespace std;
 #define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 struct  id{
    int l, r, winner;
};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n, m; cin >> n >> m;
    vector<id> a(m);
    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    for(int i = 0; i < m; i++) cin >> a[i].l >> a[i].r >> a[i].winner;
     int beater[n + 3] = {};
    for(auto &d: a){
        int l = d.l, r = d.r, winner = d.winner;
         for(auto it = s.lower_bound(l); it != s.end();){
            int val = *it;
            if(val > r) break;
            if(val == winner){
                it = s.lower_bound(val + 1);
                continue;
            }
            beater[val] = winner;
            s.erase(s.find(val));
            it = s.lower_bound(val + 1);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << beater[i] << " ";
    return 0;
}