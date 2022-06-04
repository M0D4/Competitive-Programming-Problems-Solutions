#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n, number;
    cin>>n;
    number = n-2;
    long long arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    if(n<3){
        cout<<"0\n";
        return 0;
    }
    sort(arr,arr + n);
    long long mini = arr[0], maxi = arr[n-1];
    for(int i=1; i<n-1; i++)
        if(arr[i]==mini || arr[i]==maxi)
            number--;
     cout<<number<<"\n";
    return 0;
}