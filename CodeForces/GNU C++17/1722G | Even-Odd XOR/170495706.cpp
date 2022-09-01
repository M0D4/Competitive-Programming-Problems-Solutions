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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
set<int> s;
 
int generateXors(vector<int>& a, int k){
    int n = a.size();
    int xors = 0;
    for (int i = 0; i < n - 1; ++i) {
        int x = uniform_int_distribution<int>(100,  1e7)(rng);
        while (s.count(x)){
            x = uniform_int_distribution<int>(100,  1e7)(rng);
        }
        s.insert(x);
        a[i] = x;
        xors ^= a[i];
    }
    a.back() = xors ^ k;
    return xors ^ a.back();
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    const int XOR = uniform_int_distribution<int>(1e6,  1e8)(rng);
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        int firstHalf = (n + 1) / 2;
        int secondHalf = n / 2;
        vector<int> a(firstHalf), b(secondHalf);
 
        s.clear();
 
        int x1 = generateXors(a, XOR);
        int x2 = generateXors(b, XOR);
 
        assert(x1 == x2);
 
        for (int i = 0; i < n; ++i) {
            if (i & 1) cout << b.back() << " ", s.insert(b.back()), b.pop_back();
            else cout << a.back() << " ", s.insert(a.back()), a.pop_back();
        }
        
        assert(s.size() == n);
        cout << endl;
    }
    return 0;
}