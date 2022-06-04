#include <iostream>
#include <cmath>
using namespace std;
 int main()
{
        string a;
        cin>>a;
        char current = 'a';
        int number=0;
        for(int i=0; i<a.size(); i++){
            char next = a.at(i);
            if((int)current != (int)next){
                int len1 = (int)current + 26 - (int)next;
                int len2 = (int)current - (int) next;
                int len3 = 26 - (int)current + (int)next;
                if(len1<0) len1 *=-1;
                if(len2<0) len2 *=-1;
                if(len3<0) len3 *=-1;
                int min1 = min(len1, len2);
                number += min(len3, min1);
                current = next;
            }
        }
        cout<<number<<endl;
    return 0;
}