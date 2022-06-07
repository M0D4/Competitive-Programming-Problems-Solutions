#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(!mp.count(x)) mp[x].push_back(-1);
            mp[x].push_back(i);
        }
        for(auto &i: mp){
            i.second.push_back(n);
        }
//        for(auto &i: mp)
//            for(auto &j: i.second)
//            cout << j << " ";
//        continue;
        int mn = 1e9;
        for(auto &i: mp){
            int c = 0, m = i.second.size();
            for(auto j = 1; j < m; j++){
                if(i.second[j] != i.second[j - 1] + 1) c++;
            }
            mn = min(mn, c);
        }
        cout << mn << endl;
    }
    return 0;
}