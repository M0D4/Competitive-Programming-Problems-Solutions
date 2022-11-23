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
 
const int N  = 2e5 + 5;
class FenwickTree {
private:
    vector<int> ft;
public:
    int LSOne(int x){ // least significant bit (1)
        return (x & (-x));
    }
    FenwickTree(int n) {
        ft.assign(n + 2, 0);
    }
    int rsq(int b) {
        int sum = 0;//overflow?
        for( ; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    // updates value of the k-th element by v (v can be +ve/inc or -ve/dec)
    //like freq[x]++ || freq[x]--
    void update(int k, int v) { // int v overflow?
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        FenwickTree ft(n + 2);
        ll inversions = 0;
        for (int i = 1; i <= n; ++i) {
            if(a[i - 1]) ft.update(i, a[i - 1]);
            int ones = ft.rsq(i);
            int zeros = i - ones;
            if (!a[i - 1]) inversions += ones;
        }
        ll mx = inversions;
        for (int i = 1; i <= n; ++i){
            int x = a[i - 1];
            int onesAfter = ft.rsq(i + 1, n);
            int zerosAfter = n - i - onesAfter;
            int onesBefore = i ? ft.rsq(i - 1) : 0;
            if (x){
                mx = max(mx, inversions - zerosAfter + onesBefore);
            }else{
                mx = max(mx, inversions - onesBefore + zerosAfter);
            }
        }
        cout << mx << endl;
    }
    return 0;
}