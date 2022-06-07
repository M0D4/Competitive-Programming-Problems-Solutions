#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
 
int Red, Green, Blue;
ll ans;
 
void solve(vector<ll> r, vector<ll> g, vector<ll> b){
    /*
            let the elements x, y and z;
            z <= x <= y
    */
    for(ll x: r){
        auto y = lower_bound(all(g), x); //first element equal or greater
        auto z = upper_bound(all(b), x); //first element greater
        if(y==g.end() || z==b.begin()) continue; // y not found || z is found int the first element
        z--; // decrementing pointer will give us first element lower or equal
        auto doubleIt = [](ll a){
            return a * a;
        };
        ll cc = doubleIt(x - *y) + doubleIt(x - *z) + doubleIt(*y - *z);
        if(cc < ans) ans = cc;
    }
}
int main()
{
    START
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        cin>>Red>>Green>>Blue;
        vector<ll> r(Red), g(Green), b(Blue);
        for(auto &i: r)cin>>i;
        for(auto &i: g)cin>>i;
        for(auto &i: b)cin>>i;
        sort(all(r)), sort(all(g)), sort(all(b));
        ans = LLMAX;
        solve(r, g, b);
        solve(r, b, g);
        solve(g, r, b);
        solve(g, b, r);
        solve(b, r, g);
        solve(b, g, r);
        cout<<ans<<endl;
    }
 return 0;
}
 