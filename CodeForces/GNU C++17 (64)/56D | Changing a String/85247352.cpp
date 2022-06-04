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
 const int N = 1001;
int n, m;
string s, t;
int dp[N][N];
int solve(int i, int j){
    if(i == n) return abs(m - j);
    if(j == m) return abs(n - i);
     int &ret = dp[i][j];
    if(~ret) return ret;
     ret = N;
    if(s[i] == t[j]) return ret = solve(i+1, j+1);
     ret = 1 + solve(i, j + 1); //insert
    ret = min(ret, 1 + solve(i+1, j)); //delete
    ret = min(ret, 1 + solve(i+1, j+1)); //replace
     return ret;
}
 int inc;
void build(int i, int j){
    if(i == n){
        int toAdd = m - j;
        for(int k = 0; k < toAdd; k++)
            cout << "INSERT " << i + k + inc + 1 << " " << t[j + k] << endl;
        inc += toAdd;
        return;
    }
    if(j == m){
        int toDelete = n - i;
        for(int k = 0; k < toDelete; k++){
            cout << "DELETE " << i + k + 1 + inc << endl;
            inc--;
        }
        return;
    }
    int ret = solve(i, j);
     if(s[i] == t[j]) build(i + 1, j + 1);
     else if(ret == 1 + solve(i, j + 1)){//insert
        cout << "INSERT " << i + inc++ + 1 << " " << t[j] << endl;
        build(i, j + 1);
    }
    else if(ret == 1 + solve(i + 1, j)){//delete
        cout << "DELETE " << i + inc-- + 1 << " " << endl;
        build(i + 1, j);
    }
    else if(ret == 1 + solve(i + 1, j + 1)){//replace
        cout << "REPLACE " << i + inc + 1 << " " << t[j] << endl;
        build(i + 1, j + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> s >> t;
    n = sz(s), m = sz(t);
    clr(dp, -1);
    cout << solve(0, 0) << endl;
    build(0, 0);
    return 0;
}