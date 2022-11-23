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
 
const int N = 1e9;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while(TC--){
        ll l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
        if (a == b){
            cout << "0\n";
            continue;
        }
        l += N, r += N, a += N, b += N;
        if (a - l < x && r - a < x){
            cout << "-1\n";
            continue;
        }
        if (b - l < x && r - b < x){
            cout << "-1\n";
            continue;
        }
        if (a > b) swap(a, b);
        if (b - a >= x){
            cout << "1\n";
            continue;
        }
        int mn1 = 1e9, mn2 = 1e9;
        ll cpyA = a;
        if (r - a >= x) {
            mn1 = 1;
            a = r, mn1++;
            if (a - b < x) {
                mn1++;
            }
        }
        a = cpyA;
        if (a - l >= x) {
            mn2 = 1;
            a = l, mn2++;
            if (b - a < x)
                mn2++;
        }
        cout << min(mn1, mn2) << endl;
    }
    return 0;
}