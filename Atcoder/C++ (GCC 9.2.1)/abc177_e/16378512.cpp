#include "bits/stdc++.h"

using namespace std;

#define endl            "\n"

#define sz(x)          (int) (x.size())

#define all(v)          v.begin(), v.end()

#define isOdd(n)       (n&1)

#define pow(n, m)      (ll)powl(n, m)

#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;

typedef long double ld;

typedef pair<int, int> pii;

typedef vector<int> vi;

const int N = 1e6 + 5;

int mp[N];

vector<int> sieve(N, 0);

int main()

{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, mx = 0; cin >> n;

    int a[n];

    for(auto &i: a){

            cin >> i, mp[i]++;

            if(i != 1) mx = max(mx, mp[i]);

    }

    if(!mx) return cout << "pairwise coprime", 0;

    int g = 0, p = 1;

    for(ll i = 2; i < N && p; i++){

        if(!sieve[i]){

            ll k = i, c = 0;

            while(k < N){

                sieve[k] = 1;

                c += mp[k];

                if(c > 1){

                    p = 0;

                    goto EmergencyGate;

                }

                k += i;

            }

        }

    }

    EmergencyGate:;

    if(p) return cout << "pairwise coprime", 0;

    for(int i = 0; i < n; i++) g = __gcd(g, a[i]);

    if(g == 1) return cout << "setwise coprime", 0;

    cout << "not coprime";

    return 0;

}

