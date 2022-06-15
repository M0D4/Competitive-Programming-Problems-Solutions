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
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]];
        }
        int c = 0;
        int uncompress[mp.size()];
        for(auto &it: mp)
            uncompress[c] = it.first, it.second = c++;
 
        vector<int> idx[n];
        for (int i = 0; i < n; ++i) {
            idx[mp[a[i]]].push_back(i);
        }
        vector<int> diff[n];
        for (int i = 0; i < mp.size(); ++i) {
            diff[i] = vector<int>(idx[i].size());
            for(int j = 1; j < idx[i].size(); ++j){
                diff[i][j] = idx[i][j] - idx[i][j - 1] - 1;
            }
        }
        int element = -1, first = -1, second = -1, mxFreq = -1;
        for(int i = 0; i < mp.size(); ++i){
            int mx = 0, mxG = -1, l = idx[i][0], r = -1;
            for(int j = 0; j < diff[i].size(); ++j){
                mx += 1 - diff[i][j];
                if (mx > mxG){
                    r = idx[i][j];
                    if(mx > mxFreq){
                        mxFreq = mx, first = l, second = r, element = uncompress[i];
                    }
                    mxG = mx;
                }
                if(mx <= 0){
                    mx = 1;
                    l = idx[i][j];
                }
            }
        }
 
        cout << element << " " << first + 1 << " " << second + 1 << endl;
    }
    return 0;
}