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
    int a[n];
    for(auto &i: a) cin >> i;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i != j && j != k && i != k
                   && a[i] == a[j] + a[k])
                    return cout << i + 1 << " " << j + 1 << " " << k + 1, 0;
            }
        }
    }
    cout << -1;
    return 0;
}