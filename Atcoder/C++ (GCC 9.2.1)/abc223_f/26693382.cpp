#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;


///Intermediate Overflow!!! (1 << i), x * y, 2 * x

struct Vertex{
    int mn;
    int sum;

    Vertex(){
        mn = 1e9;
        sum = 0;
    }
    Vertex(int x, int y){
        mn = x;
        sum = y;
    }
    Vertex(Vertex x, Vertex y){
        sum = x.sum + y.sum;
        mn = min(x.mn, x.sum + y.mn);
    }
};

pair<int, int> val(char c){
    if(c == '(') return {0, 1};
    return {-1, -1};
}

const int N = 2e5;

Vertex seg[N << 2];

pair<int, int> a[N];
string s;

void build(int node, int st, int ed){
    if(st == ed){
        seg[node] = Vertex(a[st].first, a[st].second);
        return;
    }

    int mid = (st + ed) >> 1;
    build(node << 1, st, mid);
    build(node << 1 | 1, mid + 1, ed);

    seg[node] = Vertex(seg[node << 1], seg[node << 1 | 1]);
}

void update(int node, int st, int ed, int& l, int& r, int& index){
    if(st > r || ed < l) return;
    if(st >= l && ed <= r){
        seg[node] = Vertex(a[index].first, a[index].second);
        return;
    }

    int mid = (st + ed) >> 1;
    update(node << 1, st, mid, l, r, index);
    update(node << 1 | 1, mid + 1, ed, l, r, index);

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

void update(int l, int r, int index){
    update(1, 0, n - 1, l, r, index);
}

Vertex query(int l, int r){
    return query(1, 0, n - 1, l, r);
}


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int q;
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        a[i] = val(s[i]);
    }

    build(1, 0, n - 1);

    while (q--){
        int t, l, r; cin >> t >> l >> r;
        --l, --r;
        if(t == 1){
            if(a[l] == a[r]) continue;
            swap(a[l], a[r]);
            update(l,  l, l);
            update(r, r, r);
        }else{
            Vertex v = query(l, r);
            cout << (v.mn >= 0 && v.sum == 0 ? "Yes" : "No") << endl;
        }
    }
    return 0;
}

