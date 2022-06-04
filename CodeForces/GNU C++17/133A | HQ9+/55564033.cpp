#include <iostream>
using namespace std;
 int main()
{
    string in ;
    cin>> in;
    int len = in.size();
    int H = in.find("H");
    int Q = in.find("Q");
    int f9  =in.find("9");
    bool isH = H>=0 && H<len;
    bool isQ =  Q>=0 && Q<len ;
    bool isf9 = f9>=0 && f9<len;
    if(isH || isQ|| isf9)
    cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}