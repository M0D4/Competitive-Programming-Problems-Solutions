#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
void count_sort(vector<int> &p, vector<int> &c){
    int n = p.size();
    {
        vector<int> cnt(n);
        for(auto x : c){
            cnt[x]++;
        }
 
        vector<int> p_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for(int i = 1; i < n; i++){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto x : p){
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        }
 
        p = p_new;
    }
 
}
 
int compare(string &s, string &t){
    int n = s.size(), m = t.size();
    if(n < m) s += string(m - n, '$');
    else if(m < n) t += string(n - m, '$');
 
    for(int i = 0; i < n; i++)
        if(s[i] < t[i]) return -1;
        else if(t[i] < s[i]) return 1;
 
    return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
    int tc; cin >> tc;
    while (tc--){
        string s; cin >> s;
        s += "$";
        int n = s.size();
        vector<int> p(n), c(n);
        {
            //k = 0
            vector<pair<char, int>> a(n);
            for(int i = 0; i < n; i++) a[i] = {s[i], i};
            sort(a.begin(), a.end());
 
            for(int i = 0; i < n; i++) p[i] = a[i].second;
            c[p[0]] = 0;
            for(int i = 1; i < n; i++){
                if(a[i].first == a[i - 1].first){
                    c[p[i]] = c[p[i - 1]];
                }else{
                    c[p[i]] = c[p[i - 1]] + 1;
                }
            }
        }
        int k = 0;
        while((1 << k) < n){
            //k -> k + 1
 
            for(int i = 0; i < n; i++){
                p[i] = (p[i] - (1 << k) + n) % n;
            }
 
            count_sort(p, c);
 
            vector<int> c_new(n);
            c_new[p[0]] = 0;
            for(int i = 1; i < n; i++){
                pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                if(now == prev){
                    c_new[p[i]] = c_new[p[i - 1]];
                }else{
                    c_new[p[i]] = c_new[p[i - 1]] + 1;
                }
            }
            c = c_new;
            k++;
        }
        string tt; cin >> tt;
        int mx = 0, m = tt.size();
        for (int len = 1; len <= min(n - 1, m); ++len) {
            for (int i = 0; i + len <= m; ++i) {
                string t = tt.substr(i, len);
                int l = 0, r = n - 1, ans = -1;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    string sub = s.substr(p[mid], t.size()); //start of the suffix
                    if(sub == t){
                        ans = mid;
                        break;
                    }
                    if(sub < t) l = mid + 1;
                    else r = mid - 1;
                }
                if(~ans) mx = max(mx, len);
            }
        }
        cout << n + m - 2 * mx - 1 << endl;
    }
    return 0;
}