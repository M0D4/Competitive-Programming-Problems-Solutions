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
 int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n], b[n];
        for(int &i: a) cin>>i;
        for(int &i: b) cin>>i;
        bool flag = 1;
        map<int, int> mp;
        for(int i  = 0; i<n; i++){
            if(a[i]==b[i]){
                mp[a[i]]++;
                continue;
            }
            if(a[i]<b[i] && !mp[1]){
                flag = 0;
                break;
            }
            if(a[i]>b[i] && !mp[-1]){
                flag  = 0;
                break;
            }
            mp[a[i]]++;
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
 return 0;
 }