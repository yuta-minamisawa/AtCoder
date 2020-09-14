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
        int k, n;
        cin >> k;
        vector<int> a;
        rep(j, k){
            int candy;
            cin >> candy;
            a.push_back(candy);
        }
        cin >> n;
        bool flag=true;
        rep(j, n){
            int b;
            cin >> b;
            if(!flag) continue;
            if(a[b-1]==0){
                flag=false;
                cout << "e-n" << endl;
            }else{
                a[b-1]--;
            }
        }
        if(flag) cout << "wa-i" << endl;
        a.clear();
    }
    return 0;
}