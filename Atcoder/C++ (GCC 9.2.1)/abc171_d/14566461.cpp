#include <bits/stdc++.h>

using namespace std;

#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<ll> vi;



const int N  = 1e5 + 5;
class FenwickTree {
    private:
        vi ft;
    public:
        int LSOne(int x){ // least significant bit (1)
            return (x & (-x));
        }
        FenwickTree(int n) {
            ft.assign(n + 1, 0);
        }
        ll rsq(int b) {
            ll sum = 0;
            for( ; b; b -= LSOne(b)) sum += ft[b];
            return sum;
        }
        ll rsq(int a, int b) {
            return rsq(b) - (a == 1 ? 0 : rsq(  a - 1));
        }
        // updates value of the k-th element by v (v can be +ve/inc or -ve/dec)
        //like freq[x]++ || freq[x]--
        void update(int k, ll v) { // note: n = ft.size() - 1
            for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
        }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);

    ll f[N] = {};
    int n; cin >> n;
    ll a[n];
    for(auto &i : a) cin >> i, f[i]++;
    FenwickTree ft(N);
    for(auto &i: a) ft.update(i, i);
    int q; cin>>q;
    while(q--){
        ll b, c; cin >> b >> c;
        if(f[b]){
            ft.update(b, -f[b] * b);
            ft.update(c, f[b] * c);
            f[c] += f[b];
            f[b] = 0;
        }
        cout<<ft.rsq(1, N)<<endl;//count of number from l to r
    }
    return 0;
}
