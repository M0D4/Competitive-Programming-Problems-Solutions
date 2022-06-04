#include "bits/stdc++.h"
 #pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 ll f(string &s){
    int ss = count(all(s), 's');
    ll sub = 0;
    for(int i = s.size() - 1; ~i; i--){
        if(s[i] == 's') ss--;
        else sub += ss;
    }
    return sub;
}
 bool comp(string &s, string &t){
    string a = s + t, b = t + s;
    return f(a) > f(b);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n; cin >> n;
    string a[n];
    for(auto &i: a) cin >> i;
    sort(a, a + n, comp);
    for(int i = 1; i < n; i++)
        a[0] += a[i];
    cout << f(a[0]);
    return 0;
}