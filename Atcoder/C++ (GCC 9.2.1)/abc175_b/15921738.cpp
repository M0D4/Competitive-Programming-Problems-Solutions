#include "bits/stdc++.h"

using namespace std;

#define pb              push_back
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

bool can(int a, int b, int c){
    vector<int> v = {a, b, c};
    sort(all(v));
    if(v[0] == v[2] || v[0] == v[1] || v[1] == v[2]) return 0;
    return v[0] + v[1] > v[2];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int a[n];
    ll c = 0;
    for(auto &i: a) cin >> i;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(can(a[i], a[j], a[k])){
                    c++;
                }
            }
        }
    }
    cout << c;
    return 0;
}
