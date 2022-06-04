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
typedef tuple<int, int, int> tii;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n; cin >> n;
    int a[n][4];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++)
            cin >> a[i][j];
    int mn = 1e9, mnIndex = 0;
    for(int i = 0; i < n; i++){
        bool ok = 1;
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                if(a[j][k] > a[i][k]) cnt++;
            }
            if(cnt == 4){
                ok = 0;
                break;
            }
        }
        if(ok && a[i][3] < mn) mn = a[i][3], mnIndex = i + 1;
    }
    cout << mnIndex;
    return 0;
}