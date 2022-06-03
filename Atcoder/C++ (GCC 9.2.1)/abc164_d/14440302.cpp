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
typedef vector<int> vi;


int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
    string s; cin>>s;
    int n = sz(s), m = 2019;
    int po10 = 1, suff =0;
    vector<int> mp(m);
    mp[suff]++;
    ll cnt = 0;
    for(int i = n-1; ~i; i--){
        int dig = s[i] - '0';
        suff = (suff + dig * po10%m)%m;
        po10 = (po10 * 10)% m;
        cnt += mp[suff];
        mp[suff]++;
    }
    cout<<cnt;
    return 0;
}
