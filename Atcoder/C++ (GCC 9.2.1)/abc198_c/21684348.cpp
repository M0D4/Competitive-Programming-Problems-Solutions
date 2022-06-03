#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;

string a[3];
map<char, int> mp;
vector<char> v;
vector<ll> ans;

bool leadingZeros(string s){
    return s[0] == '0';
}

int go(int i, int mask){
    if(i == v.size()){
        string s[3];
        for (int k = 0; k < 3; ++k) {
            s[k] = "";
            for (int j = 0; j < a[k].size(); ++j) {
                s[k].push_back(mp[a[k][j]] + '0');
            }
            if(leadingZeros(s[k]))
                return 0;
        }

        ll x = stoll(s[0]), y = stoll(s[1]), z = stoll(s[2]);
        if(x + y == z){
            ans.push_back(x);
            ans.push_back(y);
            ans.push_back(z);
            return 1;
        }
        return 0;
    }

    int ret = 0;
    for (int j = 0; j < 10; ++j) {
        if((mask >> j) & 1) continue;
        mp[v[i]] = j;
        ret |= go(i + 1, mask | (1 << j));
        mp[v[i]] = -1;
    }
    return ret;
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);


    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
        for(auto& j: a[i])
            v.push_back(j);
    }
    sort(all(v));
    Unique(v);

    if(v.size() > 10){
        return cout <<  "UNSOLVABLE", 0;
    }

    for (int i = 0; i < v.size(); ++i) {
        mp[v[i]] = -1;
    }

    go(0, 0);

    if(ans.size()){
        for (int i = 0; i < 3; ++i) {
            cout << ans[i] << endl;
        }
    }else cout << "UNSOLVABLE";
    return 0;
}