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
       ll n; cin>>n;
       ll sum = 3, p = 4;
       for(int i = 0; ; i++){
            if(n%sum==0){
                cout<<n/sum<<endl;
                break;
            }
            sum += p;
            p *= 2;
       }
    }
 return 0;
}