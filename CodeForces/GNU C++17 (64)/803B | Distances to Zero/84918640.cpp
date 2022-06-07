#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define pb       push_back
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\out.txt", "w", stdout);
    const int inf = 1e6;
 
    int n; cin >> n;
    int a[n+1], l[n + 3] = {inf}, r[n + 3] = {};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        l[i] = (a[i] ? l[i-1] : i);
    }
    r[n+1] = inf;
    for(int i = n; i > 0; i--)
        r[i] = (a[i] ? r[i+1] : i);
 
    for(int i = 1; i <= n; i++){
        cout << min(abs(i - l[i]), abs(i - r[i])) << " ";
    }
    return 0;
}