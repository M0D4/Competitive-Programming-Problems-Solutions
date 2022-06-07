#include "bits/stdc++.h"
 
using namespace std;
 
#define endl            "\n"
#define sz(x)          (int) (x.size())
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
 
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        bool ok = 0, ok2 = 0;
        for(int i = 0; i < n; i++){
            int tl, tr; cin >> tl >> tr;
            int bl, br; cin >> bl >> br;
            if(tr == bl && tl == br) ok = 1;
            if(bl == tr) ok2 = 1;
        }
        cout << (!isOdd(m) && (ok || ok2) ? "YES" : "NO") << endl;
    }
    return 0;
}