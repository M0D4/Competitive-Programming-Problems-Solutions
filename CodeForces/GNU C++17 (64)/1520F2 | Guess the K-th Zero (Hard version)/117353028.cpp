#include "bits/stdc++.h"
 
 
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-O2")
 
 
using namespace std;
 
//#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, val)    memset(x, val, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
map<pair<int, int>, int> mp;
vector<pii> v;
 
void go(int index){
    for(auto &i: v){
        --mp[i];
    }
}
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n, t; cin >> n >> t;
    while (t--){
        v.clear();
 
        int k; cin >> k;
        int l = 0, r = n - 1;
        while (l != r){
            int mid = (l + r) >> 1;
            int sum = 0, zeros = 0;
 
            if(mp.count({l, mid})) zeros = mp[{l, mid}];
            else{
                cout << "? " << l + 1 << " " << mid + 1 << endl << flush;
                cin >> sum;
                zeros = mp[{l, mid}] = (mid - l + 1) - sum;
            }
 
            if(k <= zeros) r = mid, v.push_back({l, mid});
            else k -= zeros, l = mid + 1, v.push_back({mid + 1, r});
        }
        cout << "! " << l + 1 << endl << flush;
        go(l);
    }
    return 0;
}