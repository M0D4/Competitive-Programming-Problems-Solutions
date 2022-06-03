#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

vector<int> mul;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c = 13;
    while(1){
        mul.push_back(c * 8);
        c++;
        if(c * 8 >= 1000) break;
    }

    string s; cin >> s;
    int n = s.size();

    if(n < 3){
        int x = stoi(s);
        if(x == 1)return cout << (x == 8 ? "Yes" : "No"), 0;
        if(x % 8 == 0) return cout << "Yes", 0;
        reverse(all(s));
        x = stoi(s);
        return cout << (x >= 10 && (x % 8 == 0) ? "Yes" : "No"), 0;
    }
    unordered_map<char, int> mp;
    for(auto &i: s) mp[i]++;

    for(int &num: mul){
        string x = to_string(num);
        unordered_map<char, int> y;
        for(auto &i: x) y[i]++;
        bool ok = 1;
        for(auto &i: x)
            if(mp[i] < y[i])
                ok = 0;
        if(ok)
            return cout << "Yes", 0;
    }
    cout << "No";
    return 0;
}
