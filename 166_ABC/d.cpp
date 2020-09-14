#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1000000007

long binary_square(int x, int n);

int main(){
    int x;
    cin >> x;
    vector<long> V;
    rep(i, 10000){
        //cout << i << " : " << binary_square(i, 5) << endl;
        V.push_back(binary_square(i, 5));
    }

    rep(i, 10000){
        rep2(j, i, 10000){
            if(V[j]-V[i]==x){
                cout << j << " " << i << endl;
                return 0;
            }
            if(V[i]+V[j]==x){
                cout << j << " " << -i << endl;
                return 0;
            }
        }
    }
    return 0;
}

long binary_square(int x, int n){
    // int m = MOD;
    long ans = 1;
    while(n){
        if(n%2==1){
            ans = ans * x;
        }
        x = x * x;
        n >>= 1;
    }
    return ans;
}