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
    vector<double> x, y;
    double dis[8][8];
    rep(i, n){
        double a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    rep(i, n-1){
        rep2(j, i+1, n){
            dis[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            dis[j][i] = dis[i][j];
        }
    }
    vector<int> array;
    rep(i, n){
        array.push_back(i);
    }
    double sum = 0, cnt = 0;
    do{
        cnt += 1.0;
        rep(i, n-1){
            sum += dis[array[i]][array[i+1]];
        }
    }while(next_permutation(array.begin(), array.end()));
    cout << fixed << setprecision(10) << sum / cnt << endl;
    return 0;
}