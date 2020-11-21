#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    vector<int> num(3, 0);
    string n;
    cin >> n;
    int nlen = n.size(), sum=0;
    rep(i, nlen){
        int x = n[i] - '0';
        num[x%3]++;
        sum += x;
    }
    sum %= 3;
    if(sum==0){
        cout << 0 << endl;
    }else{
        if(sum==1){
            if(num[1]){
                if(nlen!=1){
                    cout << 1 << endl;
                }else{
                    cout << -1 << endl;
                }
            }else{
                if(num[2]>=2&&nlen>2){
                    cout << 2 << endl;
                }else{
                    cout << -1 << endl;
                }
            }
        }else{
            if(num[2]){
                if(nlen!=1){
                    cout << 1 << endl;
                }else{
                    cout << -1 << endl;
                }
            }else{
                if(num[1]>=2&&nlen>2){
                    cout << 2 << endl;
                }else{
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0; 
}