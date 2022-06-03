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


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<pii> a(n);

    for(auto &i: a) cin >> i.first >> i.second;

    int c = 0;
    for(int i = 0; i < n; i++){
        int x1 = a[i].first, y1 = a[i].second;
        for(int j = i + 1; j < n; j++){
            int x2 = a[j].first, y2 = a[j].second;
            double slope = 1.0 * (y2 - y1) / (x2 - x1);
            if(isgreaterequal(slope, -1) && islessequal(slope, 1))
                c++;
        }
    }
    cout << c;
    return 0;
}
