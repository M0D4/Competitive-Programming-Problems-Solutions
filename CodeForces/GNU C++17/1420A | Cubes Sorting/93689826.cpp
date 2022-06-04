#include "bits/stdc++.h"
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
   int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int &i: a) cin >> i;
        if(is_sorted(a, a + n)){
            cout << "YES\n";
            continue;
        }
        reverse(a, a + n);
        if(is_sorted(a, a + n)){
            unordered_map<int, bool> mp;
            for(int &i: a) mp[i];
            cout << (mp.size() == n ? "NO" : "YES") << endl;
        }else cout << "YES\n";
    }
    return 0;
}