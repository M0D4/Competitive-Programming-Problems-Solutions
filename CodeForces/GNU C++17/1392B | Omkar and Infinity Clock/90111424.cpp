#include "bits/stdc++.h"
 using namespace std;
 #define pb              push_back
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
  int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll a[n], b[n], c[n];
        for(auto &i: a) cin >> i;
        ll mx = *max_element(a, a + n);
        for(int i = 0; i < n; i++) b[i] = mx - a[i];
        mx = *max_element(b, b + n);
        for(int i = 0; i < n; i++) c[i] = mx - b[i];
        if(isOdd(k)){
            for(auto &i: b) cout << i << " ";
        }else{
            for(auto &i: c) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}