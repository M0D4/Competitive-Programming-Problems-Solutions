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
        ll a, b, c; cin >> a >> b >> c;
        ll a1 = a, b1 = c;
        pii p = {-1, -1};
        if(a1 < b1) p.first = 1;
        else if(b1 < a1) p.second = b;
 
        ll aB = b * a, bB = c;
        if(aB < bB) p.first = b;
        else if(bB < aB) p.second = b;
 
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}