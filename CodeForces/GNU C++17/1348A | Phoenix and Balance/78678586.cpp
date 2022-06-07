#include <bits/stdc++.h>
#include <ext/numeric>
 
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
#define sz(x)          (int) x.size()
#define MOD 1000000007
#define EPS 1e-7
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll p1 = 1, p2 = n, sum1 = (1<<p2), sum2 = ((1<<(p2-1)));
        p2--;
        int cnt = 1;
        while(cnt<n/2) sum1+=(1<<p1), p1++, cnt++;
        cnt = 1;
        while(cnt<n/2) sum2 += (1<<p1), p1++, cnt++;
        cout<<abs(sum1 - sum2)<<endl;
    }
 return 0;
}