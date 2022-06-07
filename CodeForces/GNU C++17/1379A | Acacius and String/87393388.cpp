#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define pb       push_back
#define sz(x)    (int) (x.size())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define getVal(x)     (x == '?' ? 5 : x - 'a')
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
string  s, seek = "abacaba", goal;
int n, m = 7;
bool can(string s){
    for(int i = 0; i < m; i++){
        if(s[i] != seek[i] && s[i] != '?') return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 
    int t; cin >> t;
    while(t--){
        cin >> n >> s;
        bool ok = 0;
        goal = "";
        for(int i = 0; i + m <= n; i++){
            if(can(s.substr(i, m))){
                bool flag = 1;
                string x = s;
                for(int j = 0; j < m; j++){
                    if(s[j + i] == '?') s[j + i] = seek[j];
                }
                for(int j = 0; j + m <= n; j++){
                    if(j == i) continue;
                    if(s.substr(j, m) == seek){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    ok = 1;
                    goal = s;
                    break;
                }
                s = x;
            }
        }
        if(ok){
            for(char &c: goal) if (c == '?') c = 'd';
            cout << "YES\n" << goal << endl;
        }else cout << "NO\n";
    }
    return 0;
}