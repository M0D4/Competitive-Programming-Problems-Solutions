#include "bits/stdc++.h"

using namespace std;

#define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    const int N = 1e6 + 5;
    ll k, x = 7, c = 1; cin >> k;
    bool vis[N] = {};
    while(x % k != 0){
        if(vis[x]) break;
        vis[x] = 1;
        x = (x*10 + 7) % k;
        c++;
    }
    if(x % k) c = -1;
    cout << c;
    return 0;
}
