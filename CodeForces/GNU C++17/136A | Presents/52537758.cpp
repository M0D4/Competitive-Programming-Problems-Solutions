#include <iostream>
 using namespace std;
 int main()
{
    int len;
    cin>>len;
    int arr[len+1];
    for(int i=1; i<=len; i++)
    {
        int v;
        cin>>v;
        arr[v]=i;
    }
    for(int i=1; i<=len; i++)
        cout<<arr[i]<<" ";
     return 0;
}