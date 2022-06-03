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
#define var auto
#define MOD 1000000007


typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;


ll modPow(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    ll n; cin>>n;
    int arr[n], mp[n]={};
    for(int i = 0; i<n; i++)cin>>arr[i], mp[arr[i]]++;
    if(isOdd(n) && mp[0]!=1) return cout<<0, 0;
    if(!isOdd(n) && mp[0]!=0) return cout<<0, 0;
    for(int i=0; i<n; i++)
        if(arr[i] && mp[arr[i]]!=2)
            return cout<<0, 0;
    ll m = n/2;
    cout<<modPow(2, m, MOD);
	return 0;
}
