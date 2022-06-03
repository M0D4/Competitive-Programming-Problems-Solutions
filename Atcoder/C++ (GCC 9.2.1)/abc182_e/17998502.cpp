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

const int N = 1502;

int bulb[N][N], block[N][N], ans[N][N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int h, w, n, m; cin >> h >> w >> n >> m;



    for(int i = 0; i < n; i++){
        int r, c; cin >> r >> c;
        bulb[--r][--c] = 1;
    }

    for(int i = 0; i < m; i++){
        int r, c; cin >> r >> c;
        block[--r][--c] = 1;
    }

    n = h, m = w;
    for(int i = 0; i < n; i++){
        bool flag = 0;
        for(int j = 0; j < m; j++){
            if(bulb[i][j])
                flag = 1;
            if(block[i][j])
                flag = 0;

            ans[i][j] |= flag;
        }

        flag = 0;
        for(int j = m - 1; ~j; j--){
            if(bulb[i][j])
                flag = 1;
            if(block[i][j])
                flag = 0;

            ans[i][j] |= flag;
        }
    }

    for(int j = 0; j < m; j++){
        bool flag = 0;
        for(int i = 0; i < n; i++){
            if(bulb[i][j])
                flag = 1;
            if(block[i][j])
                flag = 0;

            ans[i][j] |= flag;
        }

        flag = 0;
        for(int i = n - 1; ~i; i--){
            if(bulb[i][j])
                flag = 1;
            if(block[i][j])
                flag = 0;

            ans[i][j] |= flag;
        }
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            c += ans[i][j];
        }
    }

    cout << c;
    return 0;
}
