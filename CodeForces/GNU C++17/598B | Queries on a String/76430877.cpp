#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
 
int fix(int k, int l, int r){
    return k%(r-l+1);
}
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    string s; cin>>s;
    int n = s.size();
    int q; cin>>q;
    while(q--){
        int l, r, k; cin>>l>>r>>k;
        l--, r--;
        k = fix(k, l, r);
        s = s.substr(0, l) + s.substr(r - k +1, k) + (r-l-k+1>0?s.substr(l, r-l-k+1):"") + (r+1<n?s.substr(r+1):"");
    }
    cout<<s;
 return 0;
}