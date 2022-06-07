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
#define EPS             1e-10
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
 
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n];
        for(auto &i: a) cin >> i;
        if(k == 1){
            cout << (a[0] == a[n - 1] ? 1 : -1) << endl;
            continue;
        }
        unordered_map<int, bool> mp;
        int c = 0;
        for(int i = 1; i < n; i++)
            if(a[i] != a[i - 1]) c++;
 
        int ans = ceil(c / ld(k - 1));
        if(!ans) ans++;
 
        cout << ans << endl;
    }
    return 0;
}