#include <iostream>
 using namespace std;
 int main()
{
    int n;
    cin>>n;
    int sum=0, capacity=0;
    for(int i=0; i<n; i++){
        int out, in;
        cin>>out>>in;
        sum -=out;
        sum +=in;
        capacity = max(sum,capacity);
    }
    cout<<capacity<<"\n";
    return 0;
}