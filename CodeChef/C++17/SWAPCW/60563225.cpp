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

    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        string s; cin >> s;
        string t = s;
        sort(all(t));
        for (int i = 0; i < n / 2; ++i) {
            if(s[i] > s[n - i - 1])
                swap(s[i], s[n - i - 1]);
        }
        cout << (s == t ? "YES" : "NO") << endl;
    }
    return 0;
}