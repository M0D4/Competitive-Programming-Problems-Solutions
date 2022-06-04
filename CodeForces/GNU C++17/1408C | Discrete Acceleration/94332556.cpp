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
        for(auto i = 1; i <= n; i++) cin >> a[i]; //0, 1, 9, 10
        a[n + 1] = len;
        ld l = 1, r = 1e9, ans = 0;
        while(fabs(l-r) >= EPS){
            ld mid = (l + r) / 2.0; //4
//            if(fabs(mid) == 4) cout << mid << endl;
            ld rem1 = mid, rem2 = mid;//4
            ll speed1 = 1, speed2 = 1;
            int i;
            for(i = 1; i <= n; i++){
                ld dis = a[i] - a[i - 1]; //8
//                cout << dis << " " << speed1 <<  " " << rem1 << endl;
                if(isless(rem1, dis / speed1)) break;///
                rem1 -= dis / speed1;//3
                speed1++;//2
            }
//            cout << a[i - 1] << " ";
            ld final1 = a[i - 1] + speed1 * rem1;//7
             for(i = n; i; i--){
                ld dis = a[i + 1] - a[i];//8
                if(isless(rem2, dis / speed2)) break;///
                rem2 -= dis /speed2;//3
                speed2++;//2
            }
//            cout << a[i + 1] << endl;
            ld final2 = a[i + 1] - speed2 * rem2;
             if(isgreaterequal(final1, final2)){
                ans = mid;
                r = mid - EPS;
            }else l = mid + EPS;
        }
        cout << ans << endl;
    }
    return 0;
}