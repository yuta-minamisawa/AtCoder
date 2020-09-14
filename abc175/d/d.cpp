#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> p, c;
    rep(i, n){
        ll x;
        cin >> x;
        p.push_back(x-1);
    }
    rep(i, n) {
        ll x;
        cin >> x;
        c.push_back(x);
    }

    ll maxim=INT64_MIN;
    rep(i, n){
        vector<ll> sum;
        ll tmpsum=0, roop=0;
        int s = i;
        while(1){
            s = p[s];
            tmpsum += c[s];
            sum.push_back(tmpsum);
            if (++roop == k || i == s) {
              break;
            }
        }
        int len = sum.size();
        if(roop==k){
            sort(sum.begin(), sum.end());
            maxim = max(maxim, sum[len-1]);
        }else{
            if(sum[len-1]>0){
                ll tmp = sum[len-1] * (k / len);
                vector<ll> over;
                s = i;
                rep(j, k%len){
                    s = p[s];
                    tmp += c[s];
                    over.push_back(tmp);
                }
                rep2(j, k%len, len){
                    s = p[s];
                    tmp += c[s];
                    over.push_back(tmp - sum[len-1]);
                }
                sort(over.begin(), over.end());
                maxim = max(maxim, over[over.size()-1]);
            }else{
                sort(sum.begin(), sum.end());
                maxim = max(maxim, sum[len - 1]);
            }
        }
        // cout << maxim << endl;
    }
    cout << maxim << endl;
    return 0;
}