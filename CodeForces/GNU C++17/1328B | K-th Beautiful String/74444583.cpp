#include <bits/stdc++.h>
#include <ext/numeric>
 using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((long long)n, (long long)m)
#define INF (int)1e9
 typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 void fast() {
 cin.tie(0);
 cout.tie(0);
 ios_base::sync_with_stdio(0);
}
 bool compare(pii &a, pii &b) {
 return a.F > b.F;
}
 ll numOfDigits(ll n) {
 if (!n) return 1;
 return (ll) (log10(n)) + 1;
}
 map<int, int> mp;
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        ll n, k, i, j ,sum = 0; cin>>n>>k;
        for(i = 1; sum<k; i++) sum +=i;
        ll group = i-1;
        //cout<<group; return 0;
        ll pos = group*(group+1)/2 - k;
        //cout<<pos; return 0;
        str s(n, 'a');
        s[n - group - 1] = 'b';
        s[n - group  + pos] = 'b';
        cout<<s<<endl;
    }
    return 0;
}
     