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
 
int n, cnt;
void gen(int open, int close, string s){
    if(cnt >= n) return;
    if(open == n && close == n){
        cout << s << endl;
        cnt++;
        return;
    }
    if(open > n || close > n) return;
    gen(open + 1, close, s + "(");
    if(open > close) gen(open, close + 1, s + ")");
}
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        cin >> n;
        cnt = 0;
        gen(0, 0, "");
    }
    return 0;
}
 