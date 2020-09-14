#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOJI 3

int main(){
    int n;
    cin >> n;
    char s[MOJI]={'a', 'b', 'c'};
    vector<int> V(n, 0);
    rep(i, n){
        cout << s[V[i]];
    }
    cout << endl;
    bool flag = true;
    while(true){
        if(V[n-1]!=2){
            V[n-1]++;
        }else{
            int dig=1;
            while(V[n-dig]==2){
                V[n-dig] = 0;
                dig++;
                if(n-dig<0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                V[n-dig]++;
            }
        }
        if(!flag){
            break;
        }
        rep(i, n){
            cout << s[V[i]];
        }
        cout << endl;
    }
    return 0;
}