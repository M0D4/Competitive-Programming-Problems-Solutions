#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        int n, k; cin >> n >> k;
        int a[n], b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
 
        map<int, int> next;
        for (int i = 0; i + 1 < n; ++i) {
            next[b[i]] = b[i + 1];
        }
 
        next[b[n - 1]] = b[n - 1] + 1;
        
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if(s.empty()) s.push(a[i]);
            else{
                while (s.size() && a[i] == next[s.top()]) s.pop();
                s.push(a[i]);
            }
        }
        cout << (s.size() <= k ? "YES" : "NO") << endl;
    }
    return 0;
}