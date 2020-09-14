#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

double length(int i, int j);

vector<int> x;
vector<int> y;

int main(){
    int n;
    double maxim=0;
    cin >> n;
    rep(i, n){
        int xnum, ynum;
        cin >> xnum >> ynum;
        x.push_back(xnum);
        y.push_back(ynum);
    }
    cout << fixed << setprecision(4);
    rep(i, n-1){
        rep2(j, i+1, n){
            maxim = max(maxim, length(i, j));
        }
    }
    cout << maxim << endl;
    return 0;
}

double length(int i, int j){
    return sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
}