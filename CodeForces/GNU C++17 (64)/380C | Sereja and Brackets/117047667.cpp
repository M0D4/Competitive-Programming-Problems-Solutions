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
 
 
 
struct group{
    int opend, closed;
    group(){
        opend = closed = 0;
    }
    group(int opend, int closed){
        this -> opend = opend;
        this -> closed = closed;
    }
};
 
group combine(group left, group right){
    group res(right.opend, left.closed);
 
    int diff = left.opend - right.closed;
    if(diff >= 0)
        res.opend += diff;
    else
        res.closed -= diff;
 
    return res;
}
 
const int N = 1e6 + 5;
 
string s;
group seg[4 * N];
 
 
void build(int node, int st, int ed){
    if(st == ed){
        seg[node] = group(s[st] == '(', s[st] == ')');
        return;
    }
 
    build(node * 2, st, (st + ed) / 2);
    build(node * 2 + 1, (st + ed) / 2 + 1, ed);
 
    seg[node] = combine(seg[node * 2], seg[node * 2 + 1]);
}
 
group query(int node, int st, int ed, int &l, int &r){
    if(st > r || ed < l) return group();
    if(st >= l && ed <= r){
        return seg[node];
    }
 
    return combine(query(node * 2, st, (st + ed) / 2, l, r),
                   query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r));
}
 
int n;
 
group query(int l, int r){
    return query(1, 0, n - 1, l, r);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    cin >> s;
    n = s.size();
 
    build(1, 0, n - 1);
 
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        group ans = query(l - 1, r - 1);
        cout << r - l + 1 - ans.opend - ans.closed << endl;
    }
    return 0;
}