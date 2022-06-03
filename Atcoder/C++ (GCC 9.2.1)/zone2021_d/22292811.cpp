#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);

    string s; cin >> s;
    deque<char> d;
    int r = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(d.empty()){
            if(s[i] != 'R') d.push_back(s[i]);
        }
        else if(s[i] == 'R') r ^= 1;
        else{
            if(r & 1) d.push_front(s[i]);
            else d.push_back(s[i]);
        }
    }
    string t = "";
    for (int i = 0; i < d.size(); ++i) {
        t.push_back(d[i]);
    }
    if(r & 1) reverse(all(t));

    d.clear();

    for (int i = 0; i < t.size(); ++i) {
        if(d.empty()) d.push_back(t[i]);
        else{
            if(d.back() != t[i]) d.push_back(t[i]);
            else d.pop_back();
        }
    }
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i];
    }
    return 0;
}