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
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[i] = x;
        }
        ll mn = 1e9;
        for(int i = 1; i <= 100; i++){
            ll need = 0;
            for(int j = 0; j < n; j++){
                if(a[j] == i) continue;
                int kk = 0, c = 0, last = -1;
                while(j < n && kk < k){
                    if(a[j] != i) last = j;
                    j++, kk++;
                }
//                if(i == 1) cout << last << endl;
                j = last;
                need++;
            }
                mn = min(mn, need);
//                cout << i << " " << need << endl;
        }
        cout << mn << endl;
    }
    return 0;
}