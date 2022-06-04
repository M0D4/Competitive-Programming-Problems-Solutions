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
 int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n, x; cin>>n>>x;
        int arr[n+1];
        ll pre[n+3] = {0};
        for(int i = 1; i<=n; i++)cin>>arr[i];
        sort(arr+1, arr+n+1, greater<int>());
        for(int i =1;i<n+1; i++) pre[i] = pre[i-1] + arr[i];
        int cnt = 0;
        ll low = 1, up = n, ans = 0;
        while(low<=up){
            ll mid = (low+up)/2;
            if(pre[mid]/(dd)mid>=x){
                ans = mid;
                low = mid+1;
            }else up = mid-1;
        }
        cout<<ans<<endl;
    }
 return 0;
 }