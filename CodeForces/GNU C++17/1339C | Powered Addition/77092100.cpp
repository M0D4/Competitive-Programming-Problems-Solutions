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
#define MOD 1000000007
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
  int main()
{
    START
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int mx = IMN, mxDiff = 0;
        for(int i =0; i<n; i++){
            int a; cin>>a;
            mx = max(mx, a);
            mxDiff = max(mxDiff, mx - a);
        }
        int steps = 0;
        while(mxDiff) mxDiff /=2, steps++;
        cout<<steps<<endl;
    }
 return 0;
}
 