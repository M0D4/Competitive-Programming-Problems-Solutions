#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
  int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            s.push_back({x, y});
        }
        sort(all(s), [](pair<int, int>& a, pair<int, int>& b){
            return a.second - a.first < b.second - b.first;
        });
        vector<vector<int>> ans;
        while (s.size()){
            pair<int, int> x = s.back();
            s.pop_back();
            for (int i = x.first; i <= x.second; ++i) {
                bool can = 1;
                for(auto& it: s){
                    if(it.first <= i && it.second >= i){
                        can = 0;
                        break;
                    }
                }
                if(can && (x.first > i - 1 || find(s.begin(), s.end(), make_pair(x.first, i - 1)) != s.end()) &&
                   (i + 1 > x.second || find(s.begin(), s.end(), make_pair(i + 1, x.second)) != s.end())){
                    ans.push_back({x.first, x.second, i});
                    break;
                }
            }
        }
        for(auto& v: ans){
            for(auto& x: v){
                cout << x << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}