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
typedef pair<string, int> psi;
typedef tuple<int, int, int> tii;
 
const int N = 2e5 + 5;
 
ll seg[4 * N], lazy[4 * N], n, a[N];
 
void build(int node, int start, int end){
    if(start == end){
        seg[node] = a[end];
        return;
    }
 
    build(node * 2, start, (start + end) / 2);
    build(node * 2 + 1, (start + end) / 2 + 1, end);
 
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}
 
void push(int node, int start, int end){
    seg[node] += lazy[node];
 
    if(start != end){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
 
    lazy[node] = 0;
}
 
void update(int node, int start, int end, int &l, int &r, int &val){
    push(node, start, end);
 
    if(start > r || end < l) return;
 
    if(start >= l && end <= r){
        lazy[node] = val;
        push(node, start, end);
        return;
    }
 
    update(node * 2, start, (start + end) / 2, l, r, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, l, r, val);
 
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}
 
void update(int l, int r, int val){
    update(1, 0, n - 1, l, r, val);
}
 
ll query(int node, int start, int end, int &l, int &r){
    push(node, start, end);
 
    if(start > r || end < l) return 1e17;
    if(start >= l && end <= r) return seg[node];
 
    return min(query(node * 2, start, (start + end) / 2, l, r),
           query(node * 2 + 1, (start + end) / 2 + 1, end, l, r));
}
 
ll query(int l, int r){
    return query(1, 0, n - 1, l, r);
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
 
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
 
    build(1, 0, n - 1);
 
    int q; cin >> q;
 
    cin.ignore();
 
    while(q--){
        string s; getline(cin, s);
        stringstream ss(s);
 
        vector<int> v;
        while(getline(ss, s, ' ')){
            v.push_back(stoi(s));
        }
 
        int l = v[0], r = v[1];
        if(v.size() == 3){
            int val = v[2];
            if(r < l){
                update(l, n - 1, val);
                update(0, r, val);
            }
            else update(l, r, val);
        }else{
            if(r < l){
                cout << min(query(l, n - 1), query(0, r)) << endl;
            }
            else cout << query(l, r) << endl;
        }
    }
 
    return 0;
}