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
    set<string> s;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        s.insert(x);
    }
    for(auto &x: s){
        if(x[0] != '!'){
            string y = "!" + x;
            if(s.count(y))
                return cout << x, 0;
        }
    }
    cout << "satisfiable";
    return 0;
}
