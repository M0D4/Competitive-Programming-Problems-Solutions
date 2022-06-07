#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
bool palindrome(string s){
    string t = s;
    reverse(all(t));
    return s == t;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int n = s.size();
        if(s == string(n, 'a')){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if(!palindrome("a" + s)){
            cout << "a" << s << endl;
        }else cout << s << "a" << endl;
    }
    return 0;
}