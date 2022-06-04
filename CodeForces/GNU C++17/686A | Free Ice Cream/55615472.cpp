#include <iostream>
//#include <algorithm>
 using namespace std;
 int main()
{
    long long n, ice, distress=0;
    cin>>n>>ice;
    for(int i=0; i<n; i++){
        char ch; int val;
        cin>>ch>>val;
        if(ch=='+')
            ice += val;
        else{
            if(ice-val>=0)
                ice -= val;
            else
                distress++;
        }
    }
    cout<<ice<<" "<<distress<<"\n";
    return 0;
}