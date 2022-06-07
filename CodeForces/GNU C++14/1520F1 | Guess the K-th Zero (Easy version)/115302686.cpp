#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
//#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))
 
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n, t; cin >> n >> t;
    while (t--){
        int k; cin >> k;
        int l = 1, r = n;
        while (l < r){
            int mid = (l + r) >> 1;
            cout << '?' << l << " " << mid << endl << flush;
            int left; cin >> left;
            int zeros = (mid - l + 1) - left;
            if(zeros >= k) r = mid;
            else k -= zeros, l = mid + 1;
        }
        cout << "! " << l << endl << flush;
    }
    exit(0);
    return 0;
}