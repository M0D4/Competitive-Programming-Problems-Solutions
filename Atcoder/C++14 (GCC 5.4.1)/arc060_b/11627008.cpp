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
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;


int arr[50];
ll dp[51][51][2505];
int n, a;
ll solve(int i, ll cnt, ll sum){
    if(i==n){
        return (cnt && sum%cnt==0 && (sum/cnt)==a);
    }

    ll &ret = dp[i][cnt][sum];

    if(~ret) return ret;

    ll c = solve(i+1, cnt+1, sum + arr[i]) + solve(i+1, cnt, sum);

    return ret = c;
}
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    cin>>n>>a;
    for(int i = 0; i<51; i++)
        for(int j = 0; j<51; j++)
            mem(dp[i][j], -1);

    for(int i =0; i<n; i++)cin>>arr[i];
    cout<<solve(0, 0, 0);
	return 0;

}
