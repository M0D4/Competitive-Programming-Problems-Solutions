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


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m; cin >> n >> m;
    char a[n + 2][m + 2];
    clr(a, '#');
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    ll c = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] != '#' && a[i][j + 1] != '#') c++;
        }
    }

    for(int col = 1; col <= m; col++){
        for(int row = 1; row <= n; row++)
            if(a[row][col] != '#' && a[row + 1][col] != '#') c++;
    }
    cout << c;
    return 0;
}
