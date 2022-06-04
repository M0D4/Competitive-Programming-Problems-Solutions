#include "bits/stdc++.h"
 #pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
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
     int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        mp[l]++;
        mp[r]--;
    }
    int j = 0;
    auto it = mp.begin();
    for(auto &i: mp){
        if(!j++) continue;
        pii p = *it;
        i.second += p.second;
        it++;
    }
    ll mx = 0, mxY = 0;
    for(auto &i: mp){
        if(i.second > mx) mx = i.second, mxY = i.first;
    }
    cout << mxY << " " << mx;
    return 0;
}