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
typedef pair<string, int> psi;
typedef tuple<int, int, int> tii;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n, k; cin >> n >> k;
    ll a[n], x = 0, y = 0;

    for(auto &i: a) cin >> i;

    for(ll bit = 41; ~bit; bit--){
        int zero = 0, one = 0;
        for(auto &i: a){
            if((i >> bit) & 1LL) one++;
            else zero++;
        }
//        cout << "bit: " << bit << ", zero: " << zero << ", one: " << one;
        if(zero >= one && (x | (1LL << bit)) <= k)
            x |= (1LL << bit);

//            cout << endl;
    }
//    cout << x; return 0;
    for(auto &i: a)
        y += x ^ i;

    cout << y;
    return 0;
}
