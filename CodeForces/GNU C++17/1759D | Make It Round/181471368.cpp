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
 
    int TC;
    cin >> TC;
    while(TC--){
        ll n, m;
        cin >> n >> m;
        int twos = 0, fives = 0;
        ll cpyN = n, cpyM = m;
 
        while (n > 1 && n % 2 == 0) twos++, n >>= 1;
        while (n > 1 && n % 5 == 0) fives++, n /= 5;
 
        ll mul = cpyN;
        ll wantMul = 1;
        for (int i = 0; ; ++i) {
            int want = 1;
            if (twos){
                twos--;
            }else want *= 2;
            if (fives){
                fives--;
            }else{
                want *= 5;
            }
            if (want <= m){
                mul *= want;
                wantMul *= want;
                m /= want;
            }else{
                break;
            }
        }
 
        cout << mul * (cpyM / wantMul) << endl;
    }
    return 0;
}