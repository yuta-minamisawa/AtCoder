#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> light;
    rep(i, m){
        int k, s;
        vector<int> tmp_light(n, 0);
        cin >> k;
        rep(j, k){
            cin >> s;
            tmp_light[s-1] = 1;
        }
        int code=0, two=1;
        rep(j, n){
            code += two * tmp_light[n-j-1];
            two <<= 1;
        }
        light.push_back(code);
    }
    vector<bool> p;
    rep(i, m){
        bool p_num;
        cin >> p_num;
        p.push_back(p_num);
    }
    int cnt=0;

    rep(bit, (1<<n)){
        int i;
        for(i=0; i<m; i++){
            int res = light[i] & bit;
            int on=0;
            rep(j, n){
                on += res%2;
                res /= 2;
            }
            if(on%2!=p[i]){
                break;
            }
        }
        if(i==m){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}

