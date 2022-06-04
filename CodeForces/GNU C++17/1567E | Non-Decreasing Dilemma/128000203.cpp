#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, int, int>;
 ///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 struct Vertex{
    int mxPrefix, mxSuff, leftMost, rightMost, len;
    ll cnt;
     Vertex(){
        mxPrefix =  mxSuff = leftMost = rightMost = len = cnt = 0;
    }
    Vertex(int x){
        mxPrefix = mxSuff = len = cnt = 1;
        leftMost = rightMost = x;
    }
    Vertex(Vertex x, Vertex y){
        cnt = x.cnt + y.cnt;
        len = x.len + y.len;
         leftMost = x.leftMost;
        rightMost = y.rightMost;
         if(x.rightMost <= y.leftMost){
            cnt -= 1LL * x.mxSuff * (x.mxSuff + 1) >> 1;
            cnt -= 1LL * y.mxPrefix * (y.mxPrefix + 1) >> 1;
             ll retCnt = x.mxSuff + y.mxPrefix;
            cnt += retCnt * (retCnt + 1) >> 1;
            if(x.mxPrefix == x.len){
                mxPrefix = x.len + y.mxPrefix;
            }else{
                mxPrefix = x.mxPrefix;
            }
            if(y.mxSuff == y.len){
                mxSuff = y.len + x.mxSuff;
            }else{
                mxSuff = y.mxSuff;
            }
        }else{
            mxPrefix = x.mxPrefix;
            mxSuff = y.mxSuff;
        }
    }
};
 const int N = 2e5;
 Vertex seg[N << 2];
int a[N];
 void build(int node, int st, int ed){
    if(st == ed){
        seg[node] = Vertex(a[st]);
        return;
    }
     int mid = (st + ed) >> 1;
    build(node << 1, st, mid);
    build(node << 1 | 1, mid + 1, ed);
     seg[node] = Vertex(seg[node << 1], seg[node << 1 | 1]);
}
 void update(int node, int st, int ed, int& index, int& val){
    if(st > index || ed < index) return;
    if(st == ed){
        seg[node] = Vertex(val);
        return;
    }
     int mid = (st + ed) >> 1;
    update(node << 1, st, mid, index, val);
    update(node << 1 | 1, mid + 1, ed, index, val);
     seg[node] = Vertex(seg[node << 1], seg[node << 1 | 1]);
}
 Vertex query(int node, int st, int ed, int& l, int& r){
    if(st > r || ed < l) return Vertex();
    if(st >= l && ed <= r){
        return seg[node];
    }
     int mid = (st + ed) >> 1;
    Vertex lq = query(node << 1, st, mid, l, r);
    Vertex rq = query(node << 1 | 1, mid + 1, ed, l, r);
     return Vertex(lq, rq);
}
 int n;
 void update(int index, int val){
    update(1, 0, n - 1, index, val);
}
 ll query(int l, int r){
    return query(1, 0, n - 1, l, r).cnt;
}
 int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
     while (q--){
        int t; cin >> t;
        if(t == 1){
            int index, value; cin >> index >> value;
            update(index - 1, value);
        }else{
            int l, r; cin >> l >> r;
            --l, --r;
            cout << query(l, r) << endl;
        }
    }
    return 0;
}