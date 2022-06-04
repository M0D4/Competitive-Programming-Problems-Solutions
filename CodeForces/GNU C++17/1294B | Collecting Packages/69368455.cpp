#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
 #define fori( tt,aa)      for(int i= tt; i<aa; i++)
#define forj( yy,bb)      for(int j=yy; j<bb; j++)
#define fork( uu,cc)      for(int k=uu; k<cc; k++)
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define EPS 1e-7
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define sc scanf
#define print printf
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 void fast(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
 ll numOfDigits(ll n);
bool compare(int &a, int &b){
    return a>b;
}
 ll pow (ll a, ll b);
 int BN (vector<pii> &x, pii &p);
 int n;
 int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        cin>>n;
        vector<pii> v(n);
        fori(0, n)cin>>v[i].F>>v[i].S;
        sort(all(v));
         bool flag = 1;
        str ans = "";
        int x = 0, y = 0;
         fori(0, n){
            if(v[i].S<y){
                flag =0;
                break;
            }
            while(x<v[i].F)ans +="R", x++;
            while(y<v[i].S)ans +="U", y++;
            x = v[i].F, y = v[i].S;
           //cout<<ans; return 0;
        }
        if(flag){
            cout<<"YES\n";
            cout<<ans<<endl;
        }else cout<<"NO\n";
     }
    return 0;
}
   int BN (vector<pii> &x, pii &p){
int low = 0;
int up = x.size()-1;
int ans = -1;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(x[mid].F<=p.F && x[mid].S>=p.S) return mid;
       if(x[mid].F<p.F) {
        low = mid+1;
    }else up = mid-1;
}
return ans;
}
 ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}