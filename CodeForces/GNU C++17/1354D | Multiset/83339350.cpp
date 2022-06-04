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
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
#define LSOne(x)  (x & (-x))   //least significant 1
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  const int N  = 1e6 + 1;
class FenwickTree {
    private:
        vi ft; //FenwickTree
    public:
        FenwickTree(int n) { // init n + 1 zeroes
            ft.assign(n + 1, 0);
        }
        int rsq(int b) { // returns RSQ(1, b)
            int sum = 0;
            for( ; b; b -= LSOne(b)) sum += ft[b];
            return sum;
        } // note: LSOne(S) (S & (-S))
        int rsq(int a, int b) {
             // returns RSQ(a, b)
            return rsq(b) - (a == 1 ? 0 : rsq(  a - 1));
        }
        // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
        //like freq[x]++ || freq[x]--
        void adjust(int k, int v) { // note: n = ft.size() - 1
            for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
        }
};
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    int n, q; cin>>n>>q;
    FenwickTree ft(N);
    for(int i = 0; i<n; i++){
        int a; cin>>a;
        ft.adjust(a, 1);
    }
    while(q--){
        int x; cin>>x;
        if(x > 0) ft.adjust(x, 1);
        else{
            x = -x;
            int l = 1, r = N - 1, ans = 0;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(ft.rsq(1, mid) >= x) ans = mid, r = mid - 1;
                else l = mid + 1;
            }
            ft.adjust(ans, -1);
        }
    }
    int m = ft.rsq(1, N - 1);
    if(!m) cout<<m;
    else{
        int l = 1, r = N - 1, ans = 0;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(ft.rsq(1, mid) >= m) ans = mid, r = mid - 1;
                else l = mid + 1;
            }
            cout<<ans;
    }
 return 0;
}