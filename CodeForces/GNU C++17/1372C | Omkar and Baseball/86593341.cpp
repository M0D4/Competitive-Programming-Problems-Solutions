#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define pb       push_back
#define sz(x)    (int) (x.size())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t;  cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b;
        for(auto &i: a) cin >> i;
        if(is_sorted(all(a))){
            cout << "0\n";
            continue;
        }
        b = a;
        sort(all(b));
        int mx = 0, l = 0, r = n - 1;
        while(l < n && a[l] == b[l]) l++;
        while(~r && a[r] == b[r]) r--;
        for(int i = l; i <= r; i++){
            if(a[i] == b[i]){
                mx++;
            }
        }
        cout << 1 + !!mx << endl;
    }
    return 0;
}