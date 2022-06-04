#include "bits/stdc++.h"
 #pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
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
 const int N = 1e5 + 5;
 int vis[N], cnt[N], steps[N];
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n; cin >> n;
    int a[n];
    for(auto &i: a) cin >> i;
     for(int i = 1; i <= n; i++){
        queue<pair<int, int>> q;
        q.push({a[i - 1], 0});
         while(q.size()){
            int num = q.front().first, c = q.front().second;
            q.pop();
             if(num > N) continue;
            if(vis[num] == i) continue;
             vis[num] = i;
            cnt[num]++;
            steps[num] += c;
             q.push({num / 2, c + 1});
            q.push({num * 2, c + 1});
        }
    }
     int mn = INT_MAX;
    for(int i = 1; i < N; i++){
        if(cnt[i] == n)
            mn = min(mn, steps[i]);
    }
    cout << mn;
    return 0;
}