#include "bits/stdc++.h"
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 3e5 + 6;
int n, a[N];
ll ans;
void change(int i, int v){
    ans -= a[0];
    if(i) ans -= max(a[i] - a[i - 1], 0);
    if(i + 1 < n) ans -= max(a[i + 1] - a[i], 0);
     a[i] = v;
    if(i) ans += max(a[i] - a[i - 1], 0);
    if(i + 1 < n) ans += max(a[i + 1] - a[i], 0);
    ans += a[0];
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
        int q; cin >> n >> q;
        ans = 0;
        memset(a, 0, n * sizeof(a[0]));
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            change(i, x);
        }
        cout << ans << endl;
        while(q--){
            int l, r; cin >> l >> r;
            l--, r--;
            int tmp = a[l];
            change(l, a[r]);
            change(r, tmp);
            cout << ans << endl;
        }
    }
    return 0;
}