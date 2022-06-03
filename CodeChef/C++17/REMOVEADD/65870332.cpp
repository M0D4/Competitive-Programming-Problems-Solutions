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

    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        int a[n];
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]];
        }
        int mxDis = mp.size();
        int l = 1, r = mxDis;
        int best = 1e9;
        while (l <= r){
            int mid = (l + r) >> 1;
            //debug(mid);
            int first = 0, last = 0, dis = 0;

            bool can = 0;
            while (first < n){
                while (last < n && dis < mid){
                    dis += mp[a[last]] == 0;
                    mp[a[last]]++;
                    last++;
                }

                if(dis == mid && last - first == mid){
                    int mn = first, mx = n - last;
                    best = min({best, 2 * mn + mx, 2 * mx + mn});
                    can = 1;
                }
                mp[a[first]]--;
                if(mp[a[first]] == 0) dis--;
                first++;
                if(first > last) last = first;
            }
            while (first < n) mp[a[first]]--, first++;
            if(can) l = mid + 1;
            else r = mid - 1;
        }
        cout << best << endl;
    }
    return 0;
}