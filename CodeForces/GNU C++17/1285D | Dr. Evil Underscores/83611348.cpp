#include <bits/stdc++.h>
 /**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
 using namespace std;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  vi v;
int solve(vi &v, int bit){
    if(bit < 0) return 0;
     vi on, off;
    for(auto &it : v){
        if(isOdd(it >> bit)) on.pb(it);
        else off.pb(it);
    }
    if(!sz(on)) return solve(off, bit - 1);
    if(!sz(off)) return solve(on, bit - 1);
     return min(solve(on, bit - 1), solve(off, bit - 1)) + (1 << bit);
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    int n; cin>>n;
    v.resize(n);
    for(auto &i: v) cin>>i;
    cout<<solve(v, 30);
 return 0;
}