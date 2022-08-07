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
 
    ll n, x, y; cin >> n >> x >> y;
    
    if (y < n)
        return cout << -1, 0;
        
    ll ok = 0, sum = 0;
    vector<ll> ans;
    for (int i = 0; i < n - 1; ++i){
        ans.push_back(1);
        ok |=  sum + 1 >= x;
        sum++;
    }
    
    y -= n - 1;
    ans.push_back(y);
    ok |= sum + y >= x || sum + y * y >= x || sum + y * y <= sum;
    
    if (ok){
        for (auto& i: ans)
            cout << i << endl;
    }else{
        cout << "-1";
    }
    return 0;
}