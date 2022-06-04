#include <bits/stdc++.h>
using namespace std;
 #define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
#define pow POW
#define INF 1e9
 typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 void fast() {
 cin.tie(0);
 cout.tie(0);
 ios_base::sync_with_stdio(0);
}
 bool compare(pii &a, pii &b) {
 return a.F > b.F;
}
 ll numOfDigits(ll n) {
 if (!n)
  return 1;
 return (ll) (log10(n)) + 1;
}
 ull POW(ll a, ll b);
 /*
 */
 ll BN();
 int main() {
 JULEE_DO_THE_THING;
 //freopen("test cases\\.txt", "r", stdin) ;
    int n; cin>>n;
    vecint a(n), b(n), c(n);
    for(auto &it: a)cin>>it;
    for(auto &it: b)cin>>it;
    for(int i=0; i<n; i++) c[i] = a[i] - b[i];
    sort(all(c));
    ll cnt = 0;
    for(int i=0; i<n; i++){
        ll low = i+1, up = n-1, ans = -1;
        while(low<=up){
            ll mid = (low+up)/2;
            //cout<<c[i]<<" "<<c[mid]<<endl;
            if(c[i] + c[mid] > 0){
                up  = mid - 1, ans = mid;
            }else low = mid+1;
        }
       // cout<<" "<<ans<<endl;
        if(ans != -1) cnt += n - ans ;
    }
    cout<<cnt;
 return 0;
}
 ll BN() {
 int low = 1;
 int up = 0;
 int ans = -1;
 while (low <= up) {
  ll mid = (((ll)low + up) / 2);
  if (mid){
   ans = mid;
   low = mid + 1;
  } else
   up = mid - 1;
 }
 return ans;
}
 ull POW(ll a, ll b) {
 ull res = 1;
 while (b > 0) {
  if (b & 1)
   res = res * a;
  a = a * a;
  b >>= 1;
 }
 return res;
}