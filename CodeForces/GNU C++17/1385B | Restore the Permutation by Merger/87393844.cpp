#include <bits/stdc++.h>
 using namespace std;
 #define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x)) //be careful of value and TLE
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
   int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[2 * n], f[n + 2] = {0};
        for(auto &i: a) cin >> i;
        for(int i = 0; i < 2 * n; i++){
            if(!f[a[i]]) cout << a[i] << " ", f[a[i]]++;
        }
        cout << endl;
    }
    return 0;
}