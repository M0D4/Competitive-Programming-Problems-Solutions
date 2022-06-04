 #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define endl "\n";
    #define MAX 10000001+9   //Maximum array size;
    #define loop(n) for(int i=0;i<n;i++)
    #define loop2(n) for(int i=0;i<n;i+=2)
    #define all(v) v.begin(),v.end()
    #define sz(v)  v.size()
    typedef vector<int> vi;
    typedef set<int> si;
     bool sortPairsCmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first * b.second < a.second * b.second;
    }
     bool isOdd(int n) { return n % 2 != 0; }
    ll c[1000000];
    ll n,total;
    ll pow(ll a, ll b) {
        ll pow = 1;
        loop(b)pow *= a;
        return pow;
        //thanks m7md :)
    }
    bool can(ll num){
        ll bolcks=0;
        ll sum=0;
        loop(n){
           if(sum+c[i]<=num){
               sum+=c[i];
           }else{
               bolcks++;
               sum=c[i];
                if(bolcks>3){
                   return false;
               }
           }
        }
        return true;
    }
    void fast() {
         cin.tie(0);
        cin.sync_with_stdio(0);
    }
     bool compare(string &s1, string &s2) {
        return s1.size() < s2.size();
    }
     //s.end() point to after last element in the set
    int main() {
         fast();
        cin>>n;
        total=0;
        ll prifix[n+9]={0};
        loop(n){
            cin>>c[i];
            prifix[i+1]=prifix[i]+c[i];
         }
        ll l=1,r=n;
        ll solu=0;
        while(l<r){
            if(prifix[n]-prifix[r-1]>prifix[l]){
                l++;
            }else if(prifix[n]-prifix[r-1]<prifix[l]){
                r--;
            }else{
                solu=prifix[l];
                l++;
            }
        }
        cout<<solu;
    }