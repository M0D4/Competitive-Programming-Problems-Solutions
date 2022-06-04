#include <bits/stdc++.h>
#include <ext/numeric>
 using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
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
typedef pair<int, int> pii;
  int main()
{
    START
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        /*
        60 = 6*10 * 2*3*2*5 = 4 * 3 * 5
        the number should be divisible by 4, 3 and by 5.
        the number id divisible by 4 if the last two digits is divisible by 4
        and the number is divisible by 3 if the sum of its digit%3==0.
        so we need number divisible by 4*5 and sum of its digits%3=0
        */
        bool divBy20 = 0;
        int digitSum = 0;
        for(int i =0; i<n; i++){
            int d = s[i] - '0';
            digitSum += d;
        }
        for(int i = 0; i<n && !divBy20; i++){
            for(int j = 0; j<n && !divBy20; j++){
                if(i==j)continue;
                int val = (s[i]-'0') * 10 + s[j]-'0';
                if(val%20==0) divBy20 = 1;
            }
        }
        if(digitSum%3==0 && divBy20)
            cout<<"red\n";
        else cout<<"cyan\n";
    }
 return 0;
}
 