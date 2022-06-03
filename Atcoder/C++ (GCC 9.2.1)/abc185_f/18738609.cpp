#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;





const int N = 4e5 + 5;

ll n, t[4*N];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = (t[v*2] ^ t[v*2+1]);
    }
}
ll xo(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return (xo(v*2, tl, tm, l, min(r, tm))
           ^ xo(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = (t[v*2] ^ t[v*2+1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q; cin >> n >> q;
    int arr[N] = {0}; // the original array
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(arr, 1, 0, N-1);
    while(q--){
        int ch; cin >> ch;
        int l, r; cin >> l >> r;
        if(ch == 2){
            cout << xo(1, 0, N-1, l - 1, r - 1)<<endl;
        }else{
            l--;
            arr[l] = (arr[l] ^ r);
            update(1, 0, N-1, l, arr[l]);
        }
    }
    return 0;
}
