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
 
    int t; cin >> t;
    while(t--){
        const int N = 2e5 + 5;
        int n; cin >> n;
        int f[N] = {}, a[n];
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[i] = x;
            f[x]++;
        }
        int mn = 1e9, x = -1;
        for(int i = 0; i < n; i++){
            if(f[a[i]] == 1 && a[i] < mn)
                mn = a[i], x = i + 1;
        }
        cout << x << endl;
    }
    return 0;
}