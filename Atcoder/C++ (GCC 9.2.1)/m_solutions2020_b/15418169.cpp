#include <bits/stdc++.h>

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

    int r, g, b, k; cin >> r >> g >> b >> k;
    int c = 0;
    while(g <= r) g *= 2, c++;
    while(b <= g) b *= 2, c++;
    if(c <= k) cout << "Yes";
    else cout << "No";
    return 0;
}
