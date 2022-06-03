#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, ll, ll>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x

void clockWise(vector<vector<char>>& a){
    int n = a[0].size();
    vector<vector<char>> b = vector<vector<char>> (n, vector<char>(n));
    for (int col = 0, row = n - 1; col < n; ++col, --row) {
        for (int i = 0; i < n; ++i) {
            b[i][col] = a[row][i];
        }
    }
    a = b;
}

void counterClockWise(vector<vector<char>>& a){
    int n = a[0].size();
    vector<vector<char>> b = vector<vector<char>> (n, vector<char>(n));
    for (int col = 0, row = 0; col < n; ++col, ++row) {
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            b[i][col] = a[row][j];
        }
    }
    a = b;
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    vector<vector<char>> a, b, tmp;
    a = b = vector<vector<char>>(n, vector<char>(n));

    int stR = n, edR = 0, stC = n, edC = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if(a[i][j] == '#'){
                stC = min(j, stC);
                stR = min(i, stR);
                edR = max(i, edR);
                edC = max(j, edC);
            }
        }
    }

    for (int i = stR; i <= edR; ++i) {
        vector<char> v;
        for (int j = stC; j <= edC; ++j) {
            v.push_back(a[i][j]);
        }
        tmp.push_back(v);
    }

    a = tmp;
    tmp.clear();



    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }


    for (int c = 0; c < 4; ++c) {
        tmp.clear();

        clockWise(b);
        stR = n, edR = 0, stC = n, edC = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(b[i][j] == '#'){
                    stC = min(j, stC);
                    stR = min(i, stR);
                    edR = max(i, edR);
                    edC = max(j, edC);
                }
            }
        }

        for (int i = stR; i <= edR; ++i) {
            vector<char> v;
            for (int j = stC; j <= edC; ++j) {
                v.push_back(b[i][j]);
            }
            tmp.push_back(v);
        }

        if(tmp == a) return cout << "Yes", 0;
    }

    cout << "No";
    return 0;
}

