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
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        string s; cin >> s;
        bool ok = 0;
        if(s.substr(0, 4) == "2020") ok = 1;
        else if(s.substr(0, 3) == "202" && s.back() == '0') ok = 1;
        else if(s.substr(0, 2) == "20" && s.substr(n - 2, 2) == "20") ok = 1;
        else if(s[0] == '2' && s.substr(n - 3, 3) == "020") ok = 1;
        else if(s.substr(n - 4, 4) == "2020") ok = 1;
 
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}