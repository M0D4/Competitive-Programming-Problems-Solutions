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
#define numOfDigits(n)  ((n)? (ll)(log10(n)+1) : 1)
#define mem(x, val)    memset(x, val, sizeof(x))
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
 const int N = 1e5;
int arr[N], n;
ll dp[N + 5];
int freq[N + 5];
ll solve(ll ai){
    if(ai>N) return 0;
      ll &ret = dp[ai];
    if(~ret) return ret;
     ret = ai * freq[ai]  + solve(ai+2);
     ret = max(ret, solve(ai+1));
     return ret;
}
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    cin>>n;
    for(int i =0; i<n; i++) cin>>arr[i], freq[arr[i]]++;
    sort(arr, arr+n);
    mem(dp, -1);
    cout<<solve(arr[0]);
    return 0;
}
 