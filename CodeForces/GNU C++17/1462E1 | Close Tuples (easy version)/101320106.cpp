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
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        int a[n];
        for(auto &i: a) cin >> i;
        sort(a, a + n);
        ll c = 0;
        for(int i = 0; i + 2 < n; i++){
            int l = i + 1, r = n - 1, ans = -1;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(a[mid] - a[i] <= 2) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            ll len;
            if(ans == -1) len = 0;
            else len = ans - i - 1;
//            cout << len << endl;
            c += len * (len + 1) >> 1LL;
        }
        cout << c << endl;
    }
    return 0;
}