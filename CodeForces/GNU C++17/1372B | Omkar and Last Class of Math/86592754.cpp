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
  ll lcm(int a, int b){
    return  1LL * a / __gcd(a, b) * b;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int t;  cin >> t;
    while(t--){
        int n; cin >> n;
        int x = n, y = n;
        ll mn = LLONG_MAX;
        for(ll i = 1; i * i <= n; i++){
            if(n%i==0){
                ll sub = n - i;
                if(sub > 0 && lcm(i, sub) < mn){
                    x = i, y = sub;
                    mn = lcm(i, sub);
                }
                sub = n - n/i;
                if(sub > 0 && lcm(n/i, sub) < mn){
                    x = n/i, y = sub;
                    mn = lcm(n/i, sub);
                }
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}