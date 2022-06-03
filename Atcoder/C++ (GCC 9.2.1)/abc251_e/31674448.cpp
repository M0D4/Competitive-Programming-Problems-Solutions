#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 3e5 + 5;

ll dp[N][2], a[N], n;

ll go(int i, bool fedFirst){
    if(i >= n){
        return (!fedFirst) * a[n - 1];
    }
    ll& ret = dp[i][fedFirst];
    if(~ret) return ret;

    ret = a[i] + go(i + 2, fedFirst || i == 0 || i == n - 1);
    ret = min(ret, (i ? a[i - 1] : 0) + go(i + 1, fedFirst));

    return ret;
}

void printPath(int i, bool fedFirst){
    if(i >= n){
        if(!fedFirst) cout << n - 1 << " ";
        return;
    }

    ll ret = go(i, fedFirst);
    if(ret == a[i] + go(i + 2, fedFirst || i == 0 || i == n - 1)){
        cout << i << " ";
        printPath(i + 2, fedFirst || i == 0 || i == n - 1);
    }else{
        printPath(i + 1, fedFirst);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    clr(dp, -1);
    cout << go(0, 0) << endl;
    return 0;
}