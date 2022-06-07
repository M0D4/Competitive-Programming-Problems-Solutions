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
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
 int f[3001] = {1,1};
 int n; cin>>n;
 for(ll i = 2; i*i<=3000; i++){
        if(!f[i]){
            ll k = i * i;
            while(k<=3000) f[k] = i, k+=i;
        }
 }
 int c = 0;
 for(int i = 1; i<=n; i++){
        int cnt = 0;
        for(ll j = 1; j*j<=i && cnt<=2; j++){
            if(i%j==0){
                if(!f[j]) cnt++;
                if(i/j!=j && !f[i/j]) cnt++;
            }
        }
        if(cnt==2) c++;
 }
 cout<<c;
 return 0;
}