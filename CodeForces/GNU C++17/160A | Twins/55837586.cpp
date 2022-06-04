#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int main(){
    int n, sum=0, counter=0, tSum=0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum +=arr[i];
    }
    sort(arr, arr+n);
    for(int i=n-1; i>=0; i--){
        counter++;
        tSum +=arr[i];
        int sub = sum - tSum;
        if(sub<tSum)
            break;
    }
    cout<<counter<<"\n";
 return 0;
}