#include "bits/stdc++.h"

using namespace std;

#define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
bool can(int a[], int mid){
    ll cost = 0;
    for(int i = 0; i < n; i++){
        cost += (a[i] - 1) / mid;
    }
    return cost <= k;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    int a[n];
    for(auto &i: a) cin >> i;
    int l = 1, r = *max_element(a, a + n), ans = r;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(can(a, mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
