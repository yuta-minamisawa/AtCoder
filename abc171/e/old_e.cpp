#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, maxim=0;
    cin >> n;
    vector<int> a;
    vector<bool> b;
    rep(i, n){
        int num;
        cin >> num;
        a.push_back(num);
        maxim = max(maxim, num);
    }
    int check = a[0];
    int digit=0;
    while(maxim>0){
        int sum=0;
        rep2(i, 1, n){
            sum += a[i]>>digit;
        }
        if(sum%2!=check%2){
            b.push_back(false);
        }else{
            b.push_back(true);
        }
        check /= 2;
        maxim /= 2;
        digit++;
    }
    int bsize=b.size();

    rep(i, n){
        rep(j, bsize){
            if(!b[j]){
                if((a[i]>>j)%2){
                    a[i] -= 1 << j;
                }else{
                    a[i] += 1 << j;
                }
            }
        }
    }
    rep(i, n){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}