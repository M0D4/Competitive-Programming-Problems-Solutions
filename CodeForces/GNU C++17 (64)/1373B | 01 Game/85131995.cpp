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
        string s; cin >> s;
        int n = sz(s);
        int z = count(all(s), '0'), o = n - z;
        int rem = abs(z - o), del = n - rem;
        cout << (isOdd(del/2) ? "DA" : "NET") << endl;
    }
    return 0;
}