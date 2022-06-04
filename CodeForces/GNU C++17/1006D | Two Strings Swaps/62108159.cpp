#include <bits/stdc++.h>
 using namespace std;
 #define endl            '\n'
#define mem(a , b)      memset(a , b , sizeof(a))
#define repeat(n)       for(int i=0; i<n; i++)
#define NumofDigits(n)  ((int)log10(n)+1)
 void quicken(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
 int main(){
    quicken();
     int n, pre=0; cin >> n;
    string a, b; cin >> a >> b;
     repeat(n)
        if(a[i]==b[i]);
        else if(a[i]==b[n-i-1] || b[i]==a[n-i-1]) swap(a[i], a[n-i-1]); /// axb bxa -> bxa bxa
        else if(b[i]==b[n-i-1])                   swap(a[i], b[n-i-1]); /// axa bxb -> bxa bxa
     repeat(n)
        pre += (a[i] != b[i]);
     cout << pre;
    return 0;
}