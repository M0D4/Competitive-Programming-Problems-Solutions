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
 int n;
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    cin>>n;
    int a[n], b[n + n], f[2*n] = {}, pos[n+1];
    for(int i = 0; i<n; i++) cin>>a[i], pos[a[i]] = i;
    for(int i = 0; i<n; i++) cin>>b[i];
    int mx = 0;
    for(int i = 0; i<n; i++){
        int in = pos[b[i]];
        int mn;
        if(in==i) mn = 0;
        else if(in < i) mn = i - in;
        else mn = n - in + i;
        f[mn]++;
        mx = max(mx, f[mn]);
    }
    cout<<mx;
 return 0;
}