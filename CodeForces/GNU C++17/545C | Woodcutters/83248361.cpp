#include <bits/stdc++.h>
#include <ext/numeric>
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  const int N = 1e5 + 5;
int x[N], h[N], n;
 int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>x[i]>>h[i];
    greedySolution:
    int cnt = 1; // for first one
    int right = x[0];
    for(int i = 1; i<n; i++){
        if(i==n-1) cnt++; //the last one
        else if(x[i] - h[i] > right) cnt++, right = x[i];
        else if(x[i] + h[i] < x[i+1]) cnt++, right = x[i] + h[i];
        else right = x[i]; //this one can't fall
    }
    cout<<cnt;
 return 0;
}