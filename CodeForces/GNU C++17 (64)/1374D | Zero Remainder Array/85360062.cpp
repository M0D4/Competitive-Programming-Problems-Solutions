#include <bits/stdc++.h>
 using namespace std;
 #define all(v)   v.begin(), v.end()
#define pb       push_back
#define sz(x)    (int) (x.size())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        map <int, int> f;
        ll c = 0, dis = 0;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            int x = k - (a % k);
            f[x%k]++;
            if(f[x%k] == 1 && x%k != 0) dis++;
        }
        ll x = 0, flag = 1;
        while(dis){
            for(auto &it : f){
                if(!it.first || !it.second) continue;
                it.second--;
                if(it.first < x) c += k - x, x = 0;
                c += ((it.first - x) + 1);
                x = it.first + 1;
                if(x >= k) x -= k;
                if(!it.second)dis--;
            }
        }
        cout << c << endl;
    }
    return 0;
}