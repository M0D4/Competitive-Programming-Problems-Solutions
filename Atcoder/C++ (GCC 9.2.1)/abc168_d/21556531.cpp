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
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;


bool is_palindrome(string s){
    string h = s;
    reverse(all(h));
    return h==s;
}


int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);

    string s; cin >> s;
    int zeros = 0, n = s.size();
    for(int i = n - 1; ~i; --i){
        if(s[i] != '0') break;
        zeros++;
    }
    cout << (is_palindrome(string(zeros, '0') + s) ? "Yes" : "No");
    return 0;
}