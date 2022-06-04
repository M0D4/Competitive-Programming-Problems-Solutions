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
  int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n, i;  cin>>n;
        str s; cin>>s;
        int two = 0;
        for(i =0; i<n; i++)
            if(s[i]=='2')two++;
         if(two==n){
            str a (n, '1'), b = a;
            cout<<a<<endl<<b<<endl;
            continue;
        }
        str a (n, ' '), b = a;
        a[0] = '1', b[0] = '1';
        for( i =1 ;i<n && s[i]!='1'; i++){
            if(s[i]=='0')  a[i] = '0', b[i] = '0';
            else a[i]='1', b[i] = '1';
        }
        if(i<n)a[i] = s[i], b[i] = '0', i++;
        for(; i<n; i++)
            a[i] = '0', b[i] = s[i];
        cout<<a<<endl;
        cout<<b<<endl;
        }
    return 0;
}
     