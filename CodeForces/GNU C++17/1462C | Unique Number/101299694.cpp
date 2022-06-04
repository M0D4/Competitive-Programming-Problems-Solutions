#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
  using namespace std;
 #define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 int a[] = {
1,
2,
3,
4,
5,
6,
7,
8,
9,
19,
29,
39,
49,
59,
69,
79,
89,
189,
289,
389,
489,
589,
689,
789,
1789,
2789,
3789,
4789,
5789,
6789,
16789,
26789,
36789,
46789,
56789,
156789,
256789,
356789,
456789,
1456789,
2456789,
3456789,
13456789,
23456789,
123456789,
-1,
-1,
-1,
-1,
-1
};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        int x; cin >> x;
        cout << a[x - 1] << endl;
    }
    return 0;
}