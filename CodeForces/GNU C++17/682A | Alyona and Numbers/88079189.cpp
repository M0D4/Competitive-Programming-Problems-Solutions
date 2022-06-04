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
     int n, m; cin >> n >> m;
    int f[5] = {};
    for(int i = 1; i <= m; i++){
        f[i%5]++;
    }
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        int r = (5 - i%5) % 5;
        cnt += f[r];
    }
    cout << cnt;
    return 0;
}