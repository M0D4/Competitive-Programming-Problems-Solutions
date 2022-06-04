#include <bits/stdc++.h>
 /**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
 using namespace std;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
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
 const int N = 100009;
int in;
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
        int rsq(int b) {
            int sum = 0;
            for( ; b; b -= LSOne(b)) sum = max(sum, ft[b]);
            return sum;
        }
        int rsq(int a, int b) {
            return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
        }
        // updates value of the k-th element by v (v can be +ve/inc or -ve/dec)
        //like freq[x]++ || freq[x]--
        void update(int k, int v) { // note: n = ft.size() - 1
            for (; k < N; k += LSOne(k)) ft[k] = max(v, ft[k]);
        }
};
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    int n; cin>>n;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i<n; i++)  cin>>a[i], mp[a[i]];
    for(auto it: mp){
        mp[it.F] = ++in;
    }
    FenwickTree ft(N);
    int mx = 0;
    for(int i = 0; i<n; i++){
        mx = ft.rsq(mp[a[i]] - 1);
        ft.update(mp[a[i]], mx + 1);
    }
    cout<<ft.rsq(N);
 return 0;
}