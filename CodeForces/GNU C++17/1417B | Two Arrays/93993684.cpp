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
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n], mid = 0, half;
        unordered_map<int, int> mp;
        unordered_map<int, bool> f;
        for(auto &i: a) cin >> i, f[i];
        for(int i = 0; i < n; i++){
            if(mp.count(a[i])) continue;
             if(a[i] * 2 == m) mid++;
            else {
                mp[a[i]] = 0;
                if(f.count(abs(m - a[i]))) mp[abs(m - a[i])] = 1;
            }
        }
        half = mid / 2;
        for(int i = 0; i < n; i++){
            if(a[i] * 2 == m){
                if(half) cout << "0 ", half--;
                else cout << "1 ";
            }else cout << mp[a[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}