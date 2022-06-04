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
 int n, m;
 int ok(string &s, string t){
     int c = 0;
    for(int i = 0; i < m && s != t; i++){
        t.push_back(t[0]);
        t.erase(0, 1);
        c++;
    }
    if(s != t) return INT_MAX;
    return c;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n;
    string a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    m = a[0].size();
     ll mn = INT_MAX;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            sum += ok(a[i], a[j]);
        }
       mn = min(mn, sum);
    }
    cout << (mn >= INT_MAX ? -1 : mn);
    return 0;
}