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
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n, p, k; cin >> n >> p >> k;
        p--;
        string s; cin >> s;
        ll x, y; cin >> x >> y;
        int need[n] = {};
        for(int i = p; i < n; i++){
            need[i%k] += (s[i] == '0');
        }
        ll mn = need[p%k] * x;
        for(int i = 0; i + 1 < n - p; i++){
            if(p + i >= p && s[p + i] == '0') need[(p + i)%k]--;
            mn = min(mn, need[(p + i + 1)%k] * x + (i + 1) * y);
        }
        cout << mn << endl;
    }
    return 0;
}