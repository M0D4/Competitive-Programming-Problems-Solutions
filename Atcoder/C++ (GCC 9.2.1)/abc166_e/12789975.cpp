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
#define sz(x)          (int) x.size()
#define MOD 1000000007
#define EPS 1e-7
#define lol    {cout<<i<<" "<<-j<<endl; goto here;}
#define lol2    {cout<<i<<" "<<j<<endl; goto here;}

typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool compare(const pii &a, const pii &b){
    return a.first > b.first;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    int n; cin>>n;
    int c1[n+1], c2[n+1];
    map<ll, ll> mp;
    for(int i = 1; i<=n; i++){
        int a; cin>>a;
        c1[i] = i + a;
        c2[i] = i - a;
        mp[c2[i]]++;
    }
    ll cnt = 0;
    for(int i =1; i<=n; i++){
        mp[c2[i]]--;
        if(mp.count(c1[i])) cnt += mp[c1[i]];
    }
    cout<<cnt;
	return 0;
}
