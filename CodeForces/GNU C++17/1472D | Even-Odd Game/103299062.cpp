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
typedef double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> even, odd;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            if(isOdd(a)) odd.push_back(a);
            else even.push_back(a);
        }
        sort(all(even));
        sort(all(odd));
        ll alice = 0, bob = 0, aliceTurn = 1;
        while(even.size() || odd.size()){
            if(aliceTurn){
                if(!even.size()) odd.pop_back();
                else if(!odd.size()) alice += even.back(), even.pop_back();
                else if(even.back() >= odd.back())
                    alice += even.back(), even.pop_back();
                else odd.pop_back();
            }else{
                if(!odd.size()) even.pop_back();
                else if(!even.size()) bob += odd.back(), odd.pop_back();
                else if(even.back() < odd.back())
                    bob += odd.back(), odd.pop_back();
                else even.pop_back();
            }
            aliceTurn ^= 1;
        }
        if(alice == bob) cout << "Tie\n";
        else cout << (alice > bob ? "Alice" : "Bob") << endl;
    }
    return 0;
}