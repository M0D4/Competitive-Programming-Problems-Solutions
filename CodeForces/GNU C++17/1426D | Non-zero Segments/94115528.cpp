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
    set<ll> s;
    ll sum = 0, c = 0;
    while(n--){
        int a; cin >> a;
        sum += a;
        if(!sum || s.count(sum)){
            c++;
            s.clear();
            sum = a;
        }
        s.insert(sum);
    }
    cout << c;
    return 0;
}