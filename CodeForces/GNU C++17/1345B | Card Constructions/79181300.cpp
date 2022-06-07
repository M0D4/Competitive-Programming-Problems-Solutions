#include <bits/stdc++.h>
#include <ext/numeric>
/**
    PROGRESS IS PROGRESS
    NO MATTER HOW SMALL
*/
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
#define MOD 1000000007
 
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
//        ll n, m; cin>>n>>m;
//        if(n>m) swap(n, m);
//        cout<<(n==1 || (n==2 && m==2)?"YES":"NO")<<endl;
 
        ll n, cnt = 0; cin>>n;
 
        while(n>0){
            ll l = 1, r = 25819,  ans = 0;
            while(l<=r){
                ll mid = (l+r)>>1;
                ll m = mid;
                ll sum = 2 * m;
                while(m>0) sum += 3*(m-1), m--;
                if(sum>n) r = mid - 1;
                else ans = sum, l = mid + 1;
            }
            if(!ans) break;
            cnt++;
            n -= ans;
        }
        cout<<cnt<<endl;
    }
 return 0;
}