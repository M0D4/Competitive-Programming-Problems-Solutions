#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        string s; cin >> s;
        ll cnt = 1;
        for (int i = 0; i < n; ++i) {
            if(binary_search(all(vowels), s[i])) continue;
            auto it = lower_bound(all(vowels), s[i]);
            ll right = 0;
            if(it != vowels.end()){
                right = s[i] - *it;
            }
            ll left = 0;
            if(it != vowels.begin()){
                --it;
                left = s[i] - *it;
            }
           
            left = abs(left), right = abs(right);
            if (left == right) cnt *= 2, cnt %= mod;
        }
        cout << cnt << endl;
    }
    return 0;
}