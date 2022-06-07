#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        for(auto &i: a) cin >> i;
        for(auto &i: b) cin >> i;
        ll l = 0, r = 1e15, ans = 0;
        while(l <= r){
            ll mid = (l + r) >> 1; //maximum couriers time
 
            ll sum = 0; //time i will spend
            bool ok = 1;
            for(int i = 0; i < n; i++){
                if(a[i] > mid){
                    sum += b[i];
                    if(sum > mid){
                        ok = 0;
                        break;
                    }
                }
            }
 
            if(ok) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}