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
 const int N = 1e5;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n, m; cin >> n >> m;
    int dis[N]; clr(dis, -1);
     dis[n] = 0;
    queue<int> q;
    q.push(n);
    while(q.size()){
        int u = q.front(); q.pop();
        if(u == m) break;
        if(u > 0 && dis[u - 1] == -1) dis[u - 1] = dis[u] + 1, q.push(u - 1);
        if(2 * u < N && dis[2 * u] == -1) dis[2 * u] = dis[u] + 1, q.push(2 * u);
    }
    cout << dis[m];
    return 0;
}