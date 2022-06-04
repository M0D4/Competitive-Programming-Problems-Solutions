#include "bits/stdc++.h"
 #pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
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
        int a[n];
        for(auto &i: a) cin >> i;
        int first = -1, last = -1;
        for(int i = 0; i < n; i++){
            if(a[i] && first == -1) first = i;
            if(a[i]) last = i;
        }
        int c = 0;
        for(int i = first; i <= last; i++) if(!a[i]) c++;
        cout << c << endl;
    }
    return 0;
}