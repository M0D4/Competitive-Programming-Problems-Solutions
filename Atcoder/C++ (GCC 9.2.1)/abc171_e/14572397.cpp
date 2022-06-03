#include <bits/stdc++.h>

using namespace std;

#define all(v)   v.begin(), v.end()
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
typedef pair<int, int> pii;
typedef vector<ll> vi;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
    ll n; cin >> n;
    int a[n];
    int x = 0;
    for(int i = 0; i<n; i++)  cin >> a[i], x ^= a[i];
    for(int i = 0; i<n; i++)
        cout<<(x^a[i])<<" ";
    return 0;
}
