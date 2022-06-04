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
    while (tc--){
        int n, k; cin >> n >> k;
        int a[n];
        vector<int> pos, neg;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] == 0) continue;
            if(a[i] >= 0) pos.push_back(a[i]);
            else neg.push_back(-a[i]);
        }
        sort(all(pos)), sort(all(neg));
        int mxPos = (pos.size() ? pos.back() : 0);
        int mxNeg = (neg.size() ? neg.back() : 0);
        ll sum = 0;
        if(mxPos >= mxNeg){
            int cnt = 0;
            if (pos.size()){
                sum += pos.back();
                while (pos.size() && cnt < k)
                    cnt++, pos.pop_back();
            }
        }else{
            int cnt = 0;
            if (neg.size()){
                sum += neg.back();
                while (neg.size() && cnt < k)
                    cnt++, neg.pop_back();
            }
        }
        for (int i = (int)pos.size() - 1; i >= 0; i -= k) {
            sum += 2 * pos[i];
        }
        for (int i = (int)neg.size() - 1; i >= 0; i -= k) {
            sum += 2 * neg[i];
        }
        cout << sum << endl;
    }
    return 0;
}