#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
bool allInt(string s){
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(!isdigit(s[i]))
            return 0;
    }
    return 1;
}
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    string s; cin>>s;
    int n = s.size();
    string a = "", b = "";
    for(int i =0; i<n; i++){
        if(s[i]==';')s[i] = ',';
    }
    if(s[n-1]==',')s.pb(','), n++;
    stringstream ss(s);
    string tmp;
    int cnt1 = 0, cnt2 = 0;
    while(getline(ss, tmp, ',')){
        if(!tmp.empty() && tmp.find('.')==-1 && (tmp[0]!='0' || tmp=="0") && allInt(tmp)){
           a += tmp;
           a.pb(',');
           cnt1++;
        }
        else {
            b += tmp;b.pb(',');
            cnt2++;
        }
    }
    if(a.empty())cout<<"-\n";
    else{
        cnt1--;
        cout<<"\"";
        for(int i =0; i<a.size(); i++){
            if(cnt1 && a[i]==',')cout<<a[i], cnt1--;
            else if(a[i]!=',')cout<<a[i];
        }
        cout<<"\"\n";
 
    }
    if(b.empty())cout<<"-\n";
    else {
        cnt2--;
        cout<<"\"";
        for(int i =0; i<b.size(); i++){
            if(cnt2 && b[i]==',')cout<<b[i], cnt2--;
            else if(b[i]!=',')cout<<b[i];
        }
        cout<<"\"\n";
    }
 return 0;
}