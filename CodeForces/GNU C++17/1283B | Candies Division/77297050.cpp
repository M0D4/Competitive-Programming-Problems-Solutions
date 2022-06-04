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
    //freopen("test cases\\in.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        /*
            we can firstly divide candies equally between children,
            then we distribute the remainder among them until we reach (k/2)th children
            here we can no longer give any child
            so the total number will be sum of candies they share equally and the extra candies from remainder.
        */
        cout<<(n/k)*k + min(k/2, n%k)<<endl;
    }
 return 0;
}
 