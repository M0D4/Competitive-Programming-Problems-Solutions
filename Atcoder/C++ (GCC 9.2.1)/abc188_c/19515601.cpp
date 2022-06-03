#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define what_is(x)      cerr << #x << " is " << x << endl;


using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int N = (1 << 16) + 5;

vector<int> a;
int seg[N * 4];

void build(int node, int st, int ed){
    if(st == ed){
        seg[node] = a[st];
        return;
    }

    int mid = (st + ed) >> 1;
    build(node * 2, st, mid);
    build(node * 2 + 1, mid + 1, ed);

    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

map<int, int> mp;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    a = vector<int>(1 << n);


    for(auto &i: a) cin >> i;
    for(int i = 0; i < (1 << n); i++) mp[a[i]] = i + 1;
    for(int i = 1; i <= 4 * (1 << n); i++)
        seg[i] = 1e9;
    build(1, 0, (1 << n) - 1);
    cout << mp[min(seg[2 * 1], seg[2 * 1 + 1])];
    return 0;
}