#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> x;
    rep(i, n){
        int num;
        cin >> num;
        x.push_back(num);
    }
    int minim=INT32_MAX;
    rep2(i, 1, 100){
        int sum=0;
        rep(j, n){
            sum += pow(x[j] - i, 2);
        }
        minim = min(sum, minim);
    }
    cout << minim << endl;
    return 0;
}