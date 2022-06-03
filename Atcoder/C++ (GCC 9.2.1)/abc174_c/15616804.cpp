#include "bits/stdc++.h"

using namespace std;

#define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define EPS 1e-7

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll k, c = 1, x = 7; cin >> k;
    if(!isOdd(k)) return cout << -1, 0;
    while(x%k != 0 && c < (int)1e7){
        x = ((x*10%k) + 7)%k;
        c++;
    }
    if(x%k != 0) c = -1;
    cout << c;
    return 0;
}
