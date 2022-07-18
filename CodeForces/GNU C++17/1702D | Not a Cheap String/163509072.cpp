#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        string s; cin >> s;
        int n = s.size(), p; cin >> p;
        priority_queue<pair<int, int>> q;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            q.push({s[i] - 'a' + 1, i});
            sum += s[i] - 'a' + 1;
        }
        vector<bool> removed(n);
        while (sum > p){
            auto top = q.top(); q.pop();
            sum -= top.first;
            removed[top.second] = 1;
        }
        for (int i = 0; i < n; ++i) {
            if(!removed[i])
                cout << s[i];
        }
        cout << endl;
    }
    return 0;
}