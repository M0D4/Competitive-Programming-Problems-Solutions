#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define Th third
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
 
 
int main()
{
    START
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        ll n, sum = 0; cin>>n;
        ll arr[n + 1], pos = 0, neg = 0;
        for(int i = 0; i<n; i++)cin>>arr[i], neg += arr[i]<0, pos += arr[i]>0;
        int mn = min(pos, neg);
        if(!mn){
            cout<<*max_element(arr, arr+n)<<endl;
            continue;
        }
        arr[n] = -1*arr[n-1];
        pos = arr[0]>0, neg = arr[0]<0;
        ll mx = arr[0];
        for(int i = 0; i<n+1; i++){
            if(arr[i]>0 && neg || (arr[i]<0 && pos)){
                if(pos) pos = 0, neg = 1;
                else pos = 1, neg = 0;
                sum += mx;
                mx = arr[i];
            }else{
                mx = max(mx, arr[i]);
            }
        }
        cout<<sum<<endl;
    }
 return 0;
}