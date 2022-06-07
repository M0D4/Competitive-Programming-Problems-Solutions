#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
const int N = 1e2 + 5;
int a[N];
vector<int> v[N];
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        v[i].resize(4);
        for (int j = 0; j < 3; ++j) {
            cin >> v[i][j];
        }
        a[v[i][1]] = m + 1;
        v[i][3] = i;
    }
    sort(v + 1, v + m + 1, [](vector<int>& x, vector<int>& y){
        return x[1] < y[1];
    });
    for (int i = 1; i <= m; ++i) {
        int need = v[i][2], cur = 0;
        for (int j = v[i][0]; j < v[i][1] && cur < need; ++j) {
            if(!a[j])
                a[j] = v[i][3], cur++;
        }
        if(cur < need){
            return cout << -1, 0;
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}