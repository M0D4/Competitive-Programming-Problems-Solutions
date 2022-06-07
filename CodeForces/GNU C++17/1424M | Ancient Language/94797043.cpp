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
 
const int N = 26 * 26 + 8, M = 1e6 + 5;
 
int in[30];
string a[M];
int ne, head[N], nxt[N], to[N];
 
void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}
 
void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 
void addBiEdge(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}
 
int val(char c){
    return c - 'a';
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n, K; cin >> n >> K;
 
    initGraph(28);
    clr(in, -1);
 
    map<int, vector<string>> mp;
    set<vector<int>> sv;
 
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        for(int j = 0; j < K; j++){
            string s; cin >> s;
            for(auto &c: s) in[val(c)] = 0;
            mp[p].push_back(s);
        }
    }
    int c = 0, ok = 1;
    for(auto &i: mp){
        for(auto &j: i.second){
            a[c++] = j;
        }
    }
    int zeros = count(in, in + 26, 0);
 
    for(int i = 0; i + 1 < c; i++){
        string s = a[i], t = a[i + 1];
        bool eq = 1;
        for(int j = 0; j < min(s.size(), t.size()); j++){
            if(s[j] != t[j]){
                eq = 0;
                vector<int> v = {val(s[j]), val(t[j])};
                if(sv.count(v)) break;
                sv.insert(v);
                addEdge(val(s[j]), val(t[j]));
                in[val(t[j])]++;
                break;
            }
        }
        if(eq && s.size() > t.size()){
            ok = 0;
            break;
        }
    }
 
    if(!ok) return cout << "IMPOSSIBLE", 0;
 
    queue <int> ready;
    for(int i = 0; i < 26; i++)
        if(!in[i])
            ready.push(i);
 
    vector<int> ans;
    while(ready.size()){
        int u = ready.front();
        ready.pop();
        ans.push_back(u);
        for(int k = head[u]; ~k; k = nxt[k]){
            int v = to[k];
            in[v]--;
            if(!in[v]) ready.push(v);
        }
    }
    if(ans.size() != zeros) return cout << "IMPOSSIBLE", 0;
    for(auto &i: ans) cout << char(i + 'a');
    return 0;
}