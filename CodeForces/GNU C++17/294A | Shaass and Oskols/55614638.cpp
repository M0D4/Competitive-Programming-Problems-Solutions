#include <iostream>
//#include <algorithm>
 using namespace std;
 int main()
{
    int n;
    cin>>n;
    int lines[n];
    for(int i=0; i<n; i++)
        cin>>lines[i];
    int shoots;
    cin>>shoots;
    for(int i=0; i<shoots; i++){
        int x, y;
        cin>>x>>y;
        if(x!=1)
            lines[x-2] += y-1;
        if(x!=n)
            lines[x] += (lines[x-1] - y);
        lines[x-1] = 0;
    }
    for(int i=0; i<n; i++)
        cout<<lines[i]<<"\n";
     return 0;
}