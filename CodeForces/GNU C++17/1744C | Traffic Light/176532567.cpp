#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'g')
                pos.push_back(i);
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c){
                auto it = lower_bound(all(pos), i);
                if (it == pos.end()){
                    int cnt = n - i - 1;
                    cnt += pos[0] + 1;
                    mx = max(mx, cnt);
                }else {
                    int idx = it - pos.begin();
                    mx = max(mx, abs(pos[idx] - i));
                }
            }
        }
        cout << mx << endl;
    }
    return 0;
}