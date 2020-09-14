#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;

    if(n==1&&m==0){
        cout << 0 << endl;
        return 0;
    }

    vector<int> ans(n, -1);

    rep(i, m){
        int s, c;
        cin >> s >> c;
        if(ans[s-1]==-1){
            ans[s-1] = c;
        }else{
            if(ans[s-1]!=c){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if(ans[0]==0&&n!=1){
        cout << -1 << endl;
        return 0;
    }

    if(ans[0]!=-1){
        cout << ans[0];
    }else{
        cout << 1;
    }

    rep2(i, 1, n){
        if(ans[i]!=-1){
            cout << ans[i];
        }else{
            cout << 0;
        }
    }
    cout << endl;

    return 0;
}