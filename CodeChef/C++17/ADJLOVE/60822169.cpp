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
        vector<int> odd, even;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if(x & 1) odd.push_back(x);
            else even.push_back(x);
        }
        vector<int> ans;
        for (int i = 0; i < odd.size() - (odd.size() % 2); ++i) {
            ans.push_back(odd[i]);
        }
        for (int i = 0; i < even.size(); ++i) {
            ans.push_back(even[i]);
        }
        if(odd.size() % 2) ans.push_back(odd.back());
        int oddPairs = 0;
        for (int i = 0; i < n - 1; ++i) {
            oddPairs += (ans[i] & 1) && (ans[i + 1] & 1);
        }
        if(oddPairs & 1){
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}