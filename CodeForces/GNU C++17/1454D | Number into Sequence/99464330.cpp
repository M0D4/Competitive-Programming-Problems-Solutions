#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 
const int N = 2e5 + 5;
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
 
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> primes;
        for(ll i = 2; i * i <= n; i++){
            if(n % i == 0){
                primes.push_back(i);
            }
        }
        if(!primes.size()) cout << "1\n" << n << endl;
        else{
            vector<ll> x(0);
            for(auto &prime: primes){
                vector<ll> v;
                ll last = prime, mul = 1;
                while(1){
                    ll rem = n / mul;
                    if((rem / prime) % prime == 0) v.push_back(prime), mul *= prime;
                    else{
                        v.push_back(rem);
                        break;
                    }
                }
                if(v.size() > x.size())
                    x = v;
            }
            cout << x.size() << endl;
            for(auto &i: x) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}