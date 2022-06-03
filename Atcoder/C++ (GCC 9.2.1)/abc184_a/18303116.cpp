#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))



typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int, int> pii;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << a * d  - b * c;
    return 0;
}
