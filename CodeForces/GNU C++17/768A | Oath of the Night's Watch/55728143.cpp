#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n, number;
    cin>>n;
    number = n;
    long long arr[n];
    long long mini = LONG_LONG_MAX, maxi = LONG_LONG_MIN;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]<mini)
            mini = arr[i];
        if(arr[i]>maxi)
            maxi = arr[i];
    }
    if(n<3){
        cout<<"0\n";
        return 0;
    }
    for(int i=0; i<n; i++)
        if(arr[i]==mini || arr[i]==maxi)
            number--;
     cout<<number<<"\n";
    return 0;
}