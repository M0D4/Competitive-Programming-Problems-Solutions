#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define Unique(x)       (x).erase(unique(all(x)), (x).end())
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define numOfDigits(x)  ((ll)log10(x)) + 1
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n; cin >> n;
    ll mn = 1000, num = numOfDigits(n);
    string s = to_string(n);

    int total = (1 << num);
    for(int i = 0; i < total; i++){
        ll x = 0, erased = 0;
        for(int j = 0; j < num; j++){
            if(i & (1 << j))
                x += (s[j] - '0');
            else erased++;
        }
        if(x % 3 == 0 && erased != num) mn = min(mn, erased);
    }

    cout << (mn == 1000 ? -1 : mn);
    return 0;
}
