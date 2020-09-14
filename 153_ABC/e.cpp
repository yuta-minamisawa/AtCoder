#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a, b;
    rep(i, n){
        int A, B;
        cin >> A >> B;
        a.push_back(A);
        b.push_back(B);
    }

    int ans=0;
    vector<bool> check(n, false);

    while(h>0){
        double mincos = DBL_MAX;
        int minind;
        rep(i, n){
            double tmpcos = (double)a[i] / b[i];
            mincos = min(tmpcos, mincos);
            if(!check[i]&&mincos==tmpcos){ 
                minind = i;
            }
            //ans += b[i] * times;
        }
        check[minind] = true;
        int times = h / a[minind];
        ans += b[minind] * times;
        h -= a[minind] * times;
    }

    cout << ans << endl;
    return 0;
}