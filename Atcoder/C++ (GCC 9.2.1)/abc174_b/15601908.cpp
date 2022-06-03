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

int dc(long double x, long double y){
    if(fabs(x-y)<=EPS) return 0;

    if(x<y) return -1;

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d; cin >> n >> d;
    int c  = 0;
    while(n--){
        ll x, y; cin >> x >> y;
        ld di = sqrt(x * x + y * y);
        if(dc(di, d) != 1) c++;
    }
    cout << c;
    return 0;
}
