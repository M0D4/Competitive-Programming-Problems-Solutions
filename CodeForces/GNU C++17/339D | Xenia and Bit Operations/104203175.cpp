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
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 
 
const int N = (1 << 17) + 5;
 
ll seg[4 * N], a[N];
 
void build(int node, int st, int ed, bool isOR){
    if(st == ed){
        seg[node] = a[st];
        return;
    }
 
    int mid = (st + ed) >> 1;
    build(node * 2, st, mid, !isOR);
    build(node * 2 + 1, mid + 1, ed, !isOR);
 
    if(isOR) seg[node] = seg[node * 2] | seg[node * 2 + 1];
    else seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}
 
void update(int node, int st, int ed, bool isOR, int &index, int &val){
    if(st > index || ed < index) return;
    if(st == ed){
        seg[node] = val;
        return;
    }
 
    int mid = (st + ed) >> 1;
    update(node * 2, st, mid, !isOR, index, val);
    update(node * 2 + 1, mid + 1, ed, !isOR, index, val);
 
    if(isOR) seg[node] = seg[node * 2] | seg[node * 2 + 1];
    else seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}
 
int n;
 
void update(bool isOR, int index, int val){
    update(1, 0, n - 1, isOR, index, val);
}
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int q; cin >> n >> q;
 
    bool isOR = isOdd(n);
    n = (1 << n);
 
    for(int i = 0; i < n; i++) cin >> a[i];
 
    build(1, 0, n - 1, isOR);
 
    while (q--){
        int index, val; cin >> index >> val;
        update(isOR, index - 1, val);
        cout << seg[1] << endl;
    }
    return 0;
}