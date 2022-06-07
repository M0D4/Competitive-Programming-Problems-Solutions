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
 
bool isPrime(ll q){
    if(q==2) return 1;
    if(q<2 || (q>2 && !(q%2))) return 0;
 
    for(ll i = 2; i*i<=q; i++)
        if(!(q%i)) return 0;
 
    return 1;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
 ll n; cin>>n;
 if(isPrime(n)) return cout<<1, 0;
    if(isPrime(n-2)) return cout<<2, 0;
    if(!isOdd(n)) cout<<2; //Goldbach conjecture
    else cout<<3;
 return 0;
}