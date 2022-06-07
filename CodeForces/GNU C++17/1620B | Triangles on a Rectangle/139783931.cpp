#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
double area(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    double x1 = a.first, x2 = b.first, x3 = c.first;
    double y1 = a.second, y2 = b.second, y3 = c.second;
 
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while(tc--){
        ll w, h; cin >> w >> h;
        vector<pair<int, int>> horizontalDown, horizontalUp, verticalLeft, verticalRight;
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            horizontalDown.push_back({x, 0});
        }
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            horizontalUp.push_back({x, h});
        }
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int y; cin >> y;
            verticalLeft.push_back({0, y});
        }
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int y; cin >> y;
            verticalRight.push_back({w, y});
        }
        double mx = area(horizontalUp[0], horizontalUp.back(), horizontalDown[0]);
        mx = max(mx, area(horizontalUp[0], horizontalUp.back(), horizontalDown.back()));
        mx = max(mx, area(horizontalUp[0], horizontalUp.back(), verticalLeft[0]));
        mx = max(mx, area(horizontalUp[0], horizontalUp.back(), verticalRight[0]));
        mx = max(mx, area(horizontalDown[0], horizontalDown.back(), horizontalUp[0]));
        mx = max(mx, area(horizontalDown[0], horizontalDown.back(), horizontalUp.back()));
        mx = max(mx, area(horizontalDown[0], horizontalDown.back(), verticalLeft.back()));
        mx = max(mx, area(horizontalDown[0], horizontalDown.back(), verticalRight.back()));
        mx = max(mx, area(verticalLeft[0], verticalLeft.back(), verticalRight.back()));
        mx = max(mx, area(verticalLeft[0], verticalLeft.back(), verticalRight[0]));
        mx = max(mx, area(verticalLeft[0], verticalLeft.back(), horizontalUp.back()));
        mx = max(mx, area(verticalLeft[0], verticalLeft.back(), horizontalDown.back()));
        mx = max(mx, area(verticalRight[0], verticalRight.back(), verticalLeft.back()));
        mx = max(mx, area(verticalRight[0], verticalRight.back(), verticalLeft[0]));
        mx = max(mx, area(verticalRight[0], verticalRight.back(), horizontalDown[0]));
        mx = max(mx, area(verticalRight[0], verticalRight.back(), horizontalUp[0]));
        cout << fixed << setprecision(0);
        cout << mx << endl;
    }
    return 0;
}