#include <bits/stdc++.h>

/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/

using namespace std;

#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;




const int MAXN = 2e5 +5 ;

int t[4*MAXN];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}
int mn(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(mn(v*2, tl, tm, l, min(r, tm))
           , mn(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
    int n, q; cin>>n>>q;
    int mx[MAXN] = {};
    pii c[MAXN];
    vector<multiset<int>> v(MAXN);
    for(int i = 0; i<n; i++){
        int rate, kg; cin>>rate>>kg;
        kg--;
        v[kg].insert(rate);
        c[i].F = rate, c[i].second = kg;
    }
    for(int i = 0; i<MAXN; i++){
        if(!sz(v[i])) mx[i] = INT_MAX;
        else mx[i] = *v[i].rbegin();
    }
    build(mx, 1, 0, MAXN-1);
    while(q--){
        int ci, d; cin>>ci>>d;
        ci--, d--;
        int currentKg = c[ci].second;
        c[ci].second = d;

        v[currentKg].erase(v[currentKg].find(c[ci].F));
        if(sz(v[currentKg]))update(1, 0, MAXN-1, currentKg, *v[currentKg].rbegin());
        else update(1, 0, MAXN-1, currentKg, INT_MAX);

        v[d].insert(c[ci].F);
        update(1, 0, MAXN-1, d, *v[d].rbegin());
        cout<<mn(1, 0, MAXN - 1, 0, MAXN-1)<<endl;
    }
    return 0;
}
