#include <bits/stdc++.h>
 using namespace std;
 #define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x)) //be careful of value and TLE
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int f[3] = {}, F = 1, FF = 0, two = 0;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            if(a == 1) f[1]++;
            else f[2]++, FF = (!two ? int(F == 1) : FF) , two = 1;
            F ^= 1;
        }
        if(f[2]){
            cout << (FF ? "First" : "Second") << endl;
        }else {
            cout << (isOdd(n) ? "First" : "Second") << endl;
        }
    }
    return 0;
}