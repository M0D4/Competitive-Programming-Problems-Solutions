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
    while (t--){
        int x, y, z; cin >> x >> y >> z;
        set<int> s = {x, y, z};
        if(s.size() == 3 || (y == z && x > y) || (x == z && y > x) || (x == y && z > x)){
            cout << "NO\n";
            continue;
        }
        if(s.size() == 1){
            cout << "YES\n" << x << " " << x << " " << x << endl;
            continue;
        }
        if(x == z){
            cout << "YES\n" << y  << " " << x << " " << y << endl;
        }
        else if(x == y){
            cout << "YES\n" << x << " " << z << " " << z << endl;
        }
        else {
            cout << "YES\n" << x << " " << x << " " << y << endl;
        }
    }
    return 0;
}