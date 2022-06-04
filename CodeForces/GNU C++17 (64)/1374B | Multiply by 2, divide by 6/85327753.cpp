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
        ll n; cin >> n;
        int c = 0;
        while(n != 1){
            if(n%6 == 0) n /= 6;
            else if(n%3 == 0) n *= 2;
            else break;
            c++;
        }
        if(n!=1) c = -1;
        cout << c << endl;
    }
    return 0;
}