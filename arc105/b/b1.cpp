#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
    }

    sort(a.begin(), a.end());
    int res = 0;

    while(1){

        // rep(i, n - 1) {
        //     if (a[i] == a[i + 1]) {
        //         a.erase(a.begin()+i);
        //         n--;
        //     }
        // }

        int minim = a[0];

        for(int i=n-1;i>0;i--){

            res += (a[i] - 1) / minim;
            a[i] %= minim;
        }

        sort(a.begin(), a.end());
        if(a[1]==0){
            break;
        }
    }

    cout << res << endl;
    return 0; 
}