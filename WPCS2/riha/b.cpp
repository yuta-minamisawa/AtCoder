#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main()
{
    int t;
    cin >> t;
    rep(i, t){
        int d, w, a;
        cin >> d >> w >> a;
        if(d/(w*a)==1){
            cout << "No";
        }else{
            cout << "Yes";
        }
        cout << endl;
    }
    return 0;
}