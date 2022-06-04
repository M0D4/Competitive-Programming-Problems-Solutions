#include <bits/stdc++.h>
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
using namespace std;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    int n; cin>>n;
    ll a[n];
    for(auto &i: a) cin>>i;
    /*
    For any subset S of size greater than 3,
    it turns out that if we pick any subset of 3 elements within it,
     then its value is greater than or equal to the value of S!
    */
     ll mx = 0;
     for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            for(int k = 0; k<n; k++)
                mx = max(mx, a[i] | a[j] | a[k]);
    cout<<mx;
 return 0;
}