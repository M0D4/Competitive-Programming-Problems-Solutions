#include <bits/stdc++.h>

using namespace std;

#define all(v)   v.begin(), v.end()
#define pb       push_back
#define sz(x)    (int) (x.size())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

pii calc(int a, int b, int c){

    ld x1, x2, discriminant, realPart, imaginaryPart;
//   "coefficients a, b and c: ";
    discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
//        cout << x1 << " " << x2 << endl;
       if(x1 == trunc(x1) && x2 == trunc(x2)) return {(int)x1, (int)x2};
       return {-1, -1};
    }

    else if (discriminant == 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
//         cout << x1 << " " << x1 << endl;
        if(x1 == trunc(x1)) return {int(x1), int(x1)};
        return {-1, -1};
    }

    else {
        return {-1, -1};
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    const int N = 1e2;

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int ans = 0;
        for(int x = 1; x <= N; x++){
            for(int y = 1; y <= N; y++){
                int a = 1, b = (x + y), c = (x * x + y * y + x * y - i);
                pii p = calc(a, b, c);
//                cout << p.first << p.second << endl;
                if(p.first > 0) ans++;
                if(p.second > 0) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
