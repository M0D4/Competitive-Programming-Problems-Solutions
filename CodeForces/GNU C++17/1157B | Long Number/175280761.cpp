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
 
    int n;
    string s;
    cin >> n >> s;
 
    char a[10];
    for (int i = 1; i <= 9; ++i) {
        cin >> a[i];
    }
 
    for (int i = 0; i < n; ++i) {
        if (a[s[i] - '0'] > s[i]){
            while (i < n && a[s[i] - '0'] >= s[i])
                s[i] = a[s[i] - '0'], ++i;
            break;
        }
    }
    cout << s;
    return 0;
}