#include <bits/stdc++.h>
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
  int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int n, i; cin >> n;
    for(i = 1; i <= n + 1; i++){
        if(i * (i + 1) / 2 > n){
            i--;
            break;
        }
    }
    cout << i << endl;
    int sum = 0;
    for(int j = 1; j < i; j++){
        sum += j;
        cout << j << " ";
    }
    if(sum < n) cout << n - sum;
    return 0;
}