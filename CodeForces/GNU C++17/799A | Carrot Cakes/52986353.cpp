#include <iostream>
using namespace std;
 int main()
{
        int64_t n, t, k, d;
        cin>>n>>t>>k>>d;
        if(n<=k){
            cout<<"NO\n";
            return 0;
        }
        else{
            double inFirstCakes = (double)n/k;
            if((int)inFirstCakes!=inFirstCakes)
                inFirstCakes = (int)inFirstCakes +1;
            int64_t minute = inFirstCakes * t;
            int64_t timeRemain = minute -d;
            int64_t timeLeft = timeRemain/t;
            int64_t SecondStarted = timeLeft*t - d;
            int64_t secondTake = t - SecondStarted;
            int64_t finish = secondTake + t;
            if(finish<minute)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
     return 0;
}