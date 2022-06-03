#include <bits/stdc++.h>

/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/

using namespace std;

#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;



const int MAXN = 2e5 + 5;

int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
    int n, q; cin>>n>>q;
    pii c[MAXN];
    vector<multiset<int>> v(MAXN);
    multiset<int> mn;
    for(int i = 0; i<n; i++){
        int rate, kg; cin>>rate>>kg;
        kg--;
        v[kg].insert(rate);
        c[i].F = rate, c[i].second = kg;
    }
    for(int i = 0; i<MAXN; i++){
        if(sz(v[i])) mn.insert(*v[i].rbegin());
    }
    while(q--){
        int in, d; cin>>in>>d;
        in--, d--;
        int currentKg = c[in].second;
        c[in].second = d;

        bool flag = 0;
        if(*v[currentKg].rbegin() == c[in].first) mn.erase(mn.find(c[in].F)), flag = 1;
        v[currentKg].erase(v[currentKg].find(c[in].F));
        if(flag && sz(v[currentKg])) mn.insert(*v[currentKg].rbegin());

        flag = 0;
        if(sz(v[d]) && *v[d].rbegin() < c[in].first) mn.erase(mn.find(*v[d].rbegin()));
        if(!sz(v[d]) || *v[d].rbegin() < c[in].first) flag = 1;
        v[d].insert(c[in].F);
        if(flag) mn.insert(*v[d].rbegin());

        cout<<*mn.begin()<<endl;
    }
    return 0;
}
