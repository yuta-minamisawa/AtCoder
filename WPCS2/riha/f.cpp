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
        int n;
        cin >> n;
        int win=0, draw=0;
        vector<int> y, k;
        rep(j, n){
            int num;
            cin >> num;
            y.push_back(num);
        }
        rep(j, n)
        {
            int num;
            cin >> num;
            k.push_back(num);
        }
        rep(j, n){
            if(y[j]==k[j]){
                draw++;
            }else{
                if(y[j]-k[j]==-1||y[j]-k[j]==2){
                    win++;
                }
            }
        }
        cout << win << " " << n - win - draw << " " << draw << endl;
    }
    return 0;
}