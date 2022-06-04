#include <bits/stdc++.h>
 using namespace std;
 #define JULEE_DO_THE_THING fast()
 #define IMIN INT_MIN
 typedef long long ll;
  void fast(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
  ll gcd(ll a, ll b){
    if(!b) return a;
    if(a%b==0) return b;
    return gcd(b, a%b);
 }
   #define MAX 15000005
int sieve[MAX];
int freq[MAX];
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\Enlarge GCD.txt", "r", stdin) ;
     //prepare for factorizing
    for(ll i = 2; i<MAX-4; i++){
        if(!sieve[i]){
            ll k = i;
            while(k<MAX-4){
                if(!sieve[k])sieve[k] = i;
                k+=i;
            }
        }
    }
    int n; cin>>n;
    int arr[n];
    map<int , bool> verify;
    ll g = 0;
    for(int i = 0; i<n; i++){
        int a; cin>>a;
        arr[i] = a;
        if(verify.size()<2)verify[a] = 1;
        g = gcd(g, a);
    }
     if(verify.size()==1) return cout<<-1, 0;
     for(int i = 0; i<n; i++) arr[i]/=g; //removing old GCD
     for(int i =  0; i<n; i++){
        int a = arr[i];
        if(a==1) continue;
        map<int, int> mp;
        while(sieve[a]>0){
            if(!mp[sieve[a]])freq[sieve[a]]++;
            mp[sieve[a]]++;
            a/=sieve[a];
        }
        if(!mp[a])freq[a]++;
    }
    int mx = IMIN;
    for(int i =2; i<MAX-1; i++){
        mx = max(mx, freq[i]);
    }
    cout<<n-mx;
    return 0;
}