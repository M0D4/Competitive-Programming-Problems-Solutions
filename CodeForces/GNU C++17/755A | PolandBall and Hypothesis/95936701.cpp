#include "bits/stdc++.h"
 
#pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
 
using namespace std;
 
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
bool isPrime(ll q){
    if(q == 2) return 1;
    if(q < 2 || (q > 2 && !(q % 2))) return 0;
 
    for(ll i = 2; i * i <= q; i++)
        if(!(q % i)) return 0;
 
    return 1;
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n; cin >> n;
    for(int i = 1; i <= 1000; i++){
        if(!isPrime(i * n + 1))
            return cout << i, 0;
    }
    return 0;
}