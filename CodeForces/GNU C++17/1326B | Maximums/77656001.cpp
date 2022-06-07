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
#define var auto
#define MOD 1000000007
 
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
 
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    int n; cin>>n;
    int b[n];
    for(int i = 0; i<n; i++)cin>>b[i];
    int x[n+1], a[n];
    x[0] = 0, a[0] = b[0];
    int mx = a[0]; x[1] = mx;
    for(int i =1; i<n; i++){
        a[i] = b[i] + x[i];
        mx  = max(mx, a[i]);
        x[i+1] = mx;
    }
    for(var &i: a)cout<<i<<" ";
 return 0;
}