#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }

    // sort(a.begin(), a.end());

    int gcd = a[0];
    vector<int> gcd1, gcd2;
    gcd1.push_back(gcd);
    rep2(i, 1, n-1){
        int A = a[i];
        while(A % gcd != 0){
            int tmp = A;
            A = gcd;
            gcd = tmp % gcd;
        }
        gcd1.push_back(gcd);
    }

    gcd = a[n-1];
    gcd2.push_back(gcd);
    rep2(i, 2, n) {
        int A = a[n-i];
        if(A < gcd){
            int tmp = A;
            A = gcd;
            gcd = tmp;
        }
        while (A % gcd != 0) {
            int tmp = A;
            A = gcd;
            gcd = tmp % gcd;
        }
        gcd2.push_back(gcd);
    }

    int res = gcd2[n-2];

    rep(i, n-2){
        int A = gcd1[i];
        int B = gcd2[n-3-i];
        if(A < B){
            int tmp = A;
            A = B;
            B = tmp;
        }
        while(A % B != 0){
            int tmp = A;
            A = B;
            B = tmp % B;
        }
        res = max(B, res);
    }

    res = max(gcd1[n-2], res);

    cout << res << endl;
    return 0;
}