#include <bits/stdc++.h>
 using namespace std;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
     const int N = 1e6 + 5;
    int t; cin>>t;
    while(t--){
        int n; cin >> n;
        cout<<n/2<<endl;
    }
    return 0;
}