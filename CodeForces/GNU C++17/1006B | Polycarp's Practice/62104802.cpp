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
     int n, k, in=0; cin >> n >> k;
    int arr[n], brr[n], sum=0;
    repeat(n) cin >> arr[i], brr[i]=arr[i];
    sort(brr, brr+n);
    reverse(brr, brr+n);
     multiset<int> s;
    repeat(k) s.insert(brr[i]), sum+=brr[i];
     cout << sum << endl;
    if(k==1) return cout << n, 0;
     for(int i=0, j=0; i<n && k-1; i++)
        if(s.find(arr[i]) != s.end())
            cout << i+1-j << " ", s.erase(s.find(arr[i])), in += i+1-j, j=i+1, k--;
     cout << n - in;
     return 0;
}