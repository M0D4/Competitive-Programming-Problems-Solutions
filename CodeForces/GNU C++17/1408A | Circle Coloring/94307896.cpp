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
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n], c[n], d[n] = {};
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;
        for(auto &i: c) cin >> i;
        for(int i = 1; i <= n; i++){
            if(i == 1) d[i - 1] = a[0];
            else{
                if(b[i - 1] != d[i - 2] && b[i - 1] != d[(i % n)]) d[i - 1] = b[i - 1];
                else if(c[i - 1] != d[i - 2] && c[i - 1] != d[(i % n)]) d[i - 1] = c[i - 1];
                else d[i - 1] = a[i - 1];
            }
        }
        for(auto &i: d) cout << i << " ";
        cout << endl;
    }
    return 0;
}