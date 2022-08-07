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
 
    int x; cin >> x;
 
    auto calc = [](int x){
      x %= 4;
      if(x == 0) return 'D';
      if(x == 1) return 'A';
      if(x == 2) return 'C';
      return 'B';
    };
    
    int a = 0, b = calc(x);
    if (calc(x + 1) < b) a = 1, b = calc(x + 1);
    if (calc(x + 2) < b) a = 2, b = calc(x + 2);
    
    cout << a << " " << char(b);
    return 0;
}