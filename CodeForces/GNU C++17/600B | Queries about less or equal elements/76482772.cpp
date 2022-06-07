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
bool allInt(string s){
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(!isdigit(s[i]))
            return 0;
    }
    return 1;
}
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int n, m; cin>>n>>m;
    int a[n], b[m];
    for(int &i: a)cin>>i;
    for(int &i: b)cin>>i;
    sort(a, a+n);
    for(int i =0; i<m; i++){
        ll low = 0, up = n-1, ans = 0, ele = b[i];
        while(low<=up){
            ll mid = (low+up)/2;
            if(a[mid]<=ele){
                ans = mid+1;
                low = mid+1;
            }else up = mid-1;
        }
        cout<<ans<<" ";
    }
 return 0;
}