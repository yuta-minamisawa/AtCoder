#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, res=0L;
    cin >> n;
    vector<ll> p(n);
    rep(i, n){
        ll x;
        cin >> x;
        p[x-1] = i;
    }
    set<ll> st;
    st.insert(p[n-1]);
    for(int i=n-2;i>=0;i--){
        ll now = p[i], disl, disr;
        st.insert(now);
        auto l = st.lower_bound(now);
        if(l!=st.begin()&&l!=++st.begin()){
            disl = *(--l) - *(--l);
        }else{
            if(l!=st.begin()){
                disl = *(--l) + 1;
            }else{
                disl = 0;
            }
        }
        auto r = st.upper_bound(now);
        if (r != st.end()) {
            disr = *r - *(--r);
        } else {
            disr = n - *(--r);
        }
        res += disl * disr * (i+1);

        l = st.lower_bound(now);
        if (l != st.begin()) {
            disl = *l - *(--l);
        } else {
            disl = *l + 1;
        }
        r = st.upper_bound(now);
        if (r != st.end() && r != --st.end()) {
            disr = *(++r) - *(--r);
        } else {
            if (r != st.end()) {
                disr = n - *r;
            } else {
                disr = 0;
            }
        }
        res += disl * disr * (i+1);
    }

    cout << res << endl;
    return 0;
}