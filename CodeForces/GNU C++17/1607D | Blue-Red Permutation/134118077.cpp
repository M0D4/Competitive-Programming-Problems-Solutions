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
using vi = vector<int>;
 
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s; cin >> s;
        
        b = a;
        sort(all(b));
        bool valid = 1;
        for (int i = 0; i < n; ++i) {
            valid &= (b[i] == i + 1);
        }
        
        if(valid){
            cout << "YES\n";
            continue;
        }
 
        priority_queue<int> red;
        priority_queue<int, vector<int>, greater<int>> blue;
 
        for (int i = 0; i < n; ++i) {
            if(s[i] == 'B') blue.push(a[i]);
            else red.push(a[i]);
        }
        map<int, bool> vis;
        bool ok = 1;
        int idx = n;
        while (red.size()){
            while (idx > 0 && vis[idx]) idx--;
            int top = red.top(); red.pop();
            if(top > idx){
                ok = 0;
                break;
            }
            vis[idx] = 1;
        }
        if(ok){
            idx = 1;
            while (blue.size()){
                while (idx <= n && vis[idx]) idx++;
                int top = blue.top(); blue.pop();
                if(top < idx){
                    ok = 0;
                    break;
                }
                vis[idx] = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}