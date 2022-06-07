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
 
    const int N = 1e6 + 5;
    string s; cin >> s;
    int n = s.size(), mx = 0;
    ll f[N] = {}, a[N] = {};
    stack<int> st;
    int c = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') st.push(i);
        else {
            if(st.empty()){
 
            }else{
                if(s[i] == ')' && s[st.top()] == '(' ||
                   s[i] == '}' && s[st.top()] == '{' ||
                   s[i] == ']' && s[st.top()] == '[' ||
                   s[i] == '>' && s[st.top()] == '<')
                            a[i] = a[st.top()] = 1;
                st.pop();
            }
        }
    }
    c = 0;
    for(int i = 0; i < n; i++){
        if(!a[i]) c = 0;
        else c += a[i], f[c]++;
    }
    f[0] = 1;
    for(int i = N - 1; ~i; i--)
        if(f[i])
            return cout << i << " " << f[i], 0;
    return 0;
}