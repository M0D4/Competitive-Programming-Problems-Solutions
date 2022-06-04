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
        ll n, cnt = 0; cin >> n;
        n++;
        int a[n + 5] = {};
        for(int i = 1; i < n; i++){
            char c; cin >> c;
            a[i] = c - '0' - 1;
            a[i] += a[i - 1];
        }
        map<ll, int> mp;
        for(int i = 1; i < n; i++){
            if(!a[i]) cnt++;
            cnt += mp[a[i]];
            mp[a[i]]++;
        }
        cout << cnt << endl;
    }
    return 0;
}