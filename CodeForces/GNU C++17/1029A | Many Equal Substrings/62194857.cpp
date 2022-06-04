#include <bits/stdc++.h>
 using namespace std;
 #define endl      '\n'
#define repeat(n) for(int i=0; i<n; i++)
 void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
 int main(){
    quicken();
     int n, k, len, no=0;
    string str, sub1="", sub2="";
    cin >> n >> k >> str;
     if(n==1){
        while(k--) cout << str;
        return 0;
    }
     for(int i=1; i<n; i++){
        sub1 = str.substr(i, n-i);
        sub2 = str.substr(0, sub1.length());
        if(sub1==sub2) {
            no=1; break;
        }
    }
     if(!no)
        while(k--) cout << str;
    else{
        cout << sub2;
        sub1 = str.substr(sub1.length(), str.length()-sub1.length());
        while(k--) cout << sub1;
    }
 }