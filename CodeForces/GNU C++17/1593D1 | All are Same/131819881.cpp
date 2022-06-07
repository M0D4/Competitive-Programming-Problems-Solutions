#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
int go(vector<int>& a){
    int cnt = 0, n = a.size();
    int g = 0;
    for (int i = 0; i < n; ++i) {
        int rem = a[i] - a[0];
        g = __gcd(g, rem);
    }
    return g;
}
 
void solveOne(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    Unique(a);
    n = a.size();
 
    if(1 == n){
        cout << "-1\n";
        return;
    }
 
    cout << go(a) << endl;
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
    int tc; cin >> tc;
    while (tc--){
        solveOne();
    }
    return 0;
}
 