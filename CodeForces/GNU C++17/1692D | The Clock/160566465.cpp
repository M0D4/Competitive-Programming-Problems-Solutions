#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
bool is_palindrome(string s){
    string h = s;
    reverse(all(h));
    return h == s;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        string s; cin >> s;
        int m; cin >> m;
        map<string, bool> mp;
        int cnt = 0;
        while (mp[s] == 0){
            mp[s] = 1;
            if(is_palindrome(s))
                cnt++;
            int hour = stoi(s.substr(0, 2)), minute = stoi(s.substr(3));
            minute += m;
            if(minute >= 60) hour += minute / 60, minute %= 60;
            if(hour >= 24) hour %= 24;
            string tmp = "";
            if (hour <= 9) tmp += "0";
            tmp += to_string(hour);
            tmp += ":";
            if(minute <= 9) tmp += "0";
            tmp += to_string(minute);
            s = tmp;
        }
        cout << cnt << endl;
    }
    return 0;
}