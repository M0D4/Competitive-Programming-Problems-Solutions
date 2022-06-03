#include "bits/stdc++.h"

using namespace std;

#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    pair<int, int> d1, d2;
    for(int i = 0; i < n; i++){
        int a1, a2; cin >> a1 >> a2;
        if(!i) d1 = {a1, a2};
        else if(i == 1) d2 = {a1, a2};
        else{
            if(d1.first == d1.second && d2.first == d2.second &&  a1 ==  a2)
                return cout << "Yes", 0;
            d1 = d2, d2 = {a1, a2};
        }
    }
    cout << "No";
    return 0;
}
