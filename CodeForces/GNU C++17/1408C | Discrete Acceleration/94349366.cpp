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
      cout << fixed << setprecision(9);
     int t; cin >> t;
    while(t--){
        ll n, len; cin >> n >> len;
        int a[n + 2] = {};
        for(auto i = 1; i <= n; i++) cin >> a[i];
         a[n + 1] = len;
         ld l = 1, r = 1e9, ans = 0;
         while(fabs(l - r) >= EPS){
            ld mid = (l + r) / 2.0;
            ld rem_time1 = mid, rem_time2 = mid;
            ll speed1 = 1, speed2 = 1;
            int i;
            for(i = 1; i <= n; i++){
                ld dis = a[i] - a[i - 1];
                if(isless(rem_time1, dis / speed1)) break;
                rem_time1 -= dis / speed1;
                speed1++;
            }
             ld final_pos1 = a[i - 1] + speed1 * rem_time1;
             for(i = n; i; i--){
                ld dis = a[i + 1] - a[i];
                if(isless(rem_time2, dis / speed2)) break;
                rem_time2 -= dis /speed2;
                speed2++;
            }
             ld final_pos2 = a[i + 1] - speed2 * rem_time2;
             if(isgreaterequal(final_pos1, final_pos2)){
                ans = mid;
                r = mid - EPS;
            }else l = mid + EPS;
        }
        cout << ans << endl;
    }
    return 0;
}