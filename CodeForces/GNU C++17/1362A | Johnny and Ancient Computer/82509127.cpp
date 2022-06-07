#include <bits/stdc++.h>
#include <ext/numeric>
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
#define MAX (ll) 1e18
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
ll a, b;
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    int t; cin>>t;
    while(t--){
        cin>>a>>b;
        ll c = 0, x = a;
        while(x<<3 <= b) x <<= 3, c++;
        while(x<<2 <= b) x <<= 2, c++;
        while(x<<1 <= b) x <<= 1, c++;
        while(x%8==0 && x>>3 >= b) x >>= 3, c++;
        while(x%4==0 && x>>2 >= b) x >>= 2, c++;
        while(x%2==0 && x>>1 >= b) x >>= 1, c++;
        if(x!=b) cout<<"-1\n";
        else cout<<c<<endl;
    }
 return 0;
}