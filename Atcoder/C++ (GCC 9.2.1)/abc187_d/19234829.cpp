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
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

ll ao;

bool com(pii &a, pii &b){
    return a.first * 2LL + a.second > b.first * 2LL + b.second;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<pii> a(n);

    ll tak = 0;

    for(auto &i: a) cin >> i.first >> i.second, ao += i.first;

    sort(all(a), com);

    int c = 0;

    for(int i = 0; i < n && tak <= ao; i++){
        tak += a[i].first + a[i].second;
        ao -= a[i].first;
        c++;
    }

    cout << c;
    return 0;
}
