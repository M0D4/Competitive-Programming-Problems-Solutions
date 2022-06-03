#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;


///Intermediate Overflow!!! (1 << i), x * y, 2 * x

const int N = 100 + 5;
int n, m;

char a[N][N];
int score[N], ans[N];
pair<int, int> player[N];

int play(char x, char y){
    if(x == y) return 2;
    if(x == 'G') return (y == 'C');
    if(x == 'C') return (y == 'P');
    if(x == 'P') return (y == 'G');
    return 0;
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < 2 * n; ++i) {
        score[i] = 0;
        player[i] = {0, i};
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= m; ++i) {
        if(i){
            for (int k = 1; k <= n; ++k) {
                pair<int, int>& p1 = player[2 * k - 2], &p2 = player[2 * k - 1];
                int game = play(a[p1.second][i - 1], a[p2.second][i - 1]);
                if(game == 1) p1.first++;
                else if(game == 0) p2.first++;
            }
        }
        sort(player, player + 2 * n, [](pair<int, int>& a, pair<int, int>& b){
           if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
    }
    for (int i = 0; i < n * 2; ++i) {
        cout << player[i].second + 1 << endl;
    }
    return 0;
}

