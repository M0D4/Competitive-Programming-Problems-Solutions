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
 
string suff[] = {"00", "25", "50", "75"};
 
int main()
{
//    ios_base::sync_with_stdio(0), cin.tie(0);
 
    ll n; scanf("%lld", &n);
    string s = to_string(n);
    n = s.size();
 
    int mn = 1e9;
    for (int i = 0; i < 4; ++i) {
        string t = s;
        int steps = 0;
        for (int j = n - 1; ~j; --j) {
            if(t[j] == suff[i][1]){
                t.erase(j, 1);
                t.push_back(suff[i][1]);
                steps += (n - 1 - j);
                break;
            }
        }
        for (int j = n - 2; j >= 0; --j) {
            if(t[j] == suff[i][0]){
                t.erase(j, 1);
                t.push_back(suff[i][0]);
                swap(t[n - 2], t.back());
                steps += (n - 2 - j);
                break;
            }
        }
 
        if(t.size() < 2 || t.substr(n - 2, 2) != suff[i]) continue;
        if(t[0] == '0'){
            for (int j = 0; j + 2 < n; ++j) {
                if(t[j] != '0'){
                    swap(t[j], t[0]);
                    steps += j;
                    break;
                }
            }
        }
        if(t[0] == '0') continue;
        mn = min(mn, steps);
    }
    if(mn == 1e9) mn = -1;
    printf("%d", mn);
    return 0;
}