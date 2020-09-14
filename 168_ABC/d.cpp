#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define INFTY INT32_MAX

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    vector<int> sign(n, INT32_MAX);
    vector<int> sirube(n, INFTY);
    vector<vector<int>> load;
    vector<int> state(n, 0);
    queue<int> search;
    sign[0] = 0;

    rep(i, n){
        vector<int> tmp, tmp2;
        load.push_back(tmp2);
        //state.push_back(tmp);
    }

    vector<int> check(n, 0);

    rep(i, m){
        int A, B;
        cin >> A >> B;
        a.push_back(A);
        b.push_back(B);
        load[A-1].push_back(B-1);
        load[B-1].push_back(A-1);
        if(A==1){
            sign[B-1] = 1;
            sirube[B-1] = 1;
            check[B-1]=1;
            search.push(B-1);
        }
        if(B==1){
            sign[A-1] = 1;
            sirube[A-1] = 1;
            check[A-1]=1;
            search.push(A-1);
        }
    }



    while(!search.empty()){
        int p = search.front();
        search.pop();
        rep(i, load[p].size()){
            int c = load[p][i];
            if(check[c]) continue;
            sign[c] = p+1;
            check[c] = 1;
            search.push(c);
        }
    }

    bool flag = true;
    rep2(i, 1, n){
        if(sign[i]==INT32_MAX){
            flag = false;
            cout << "No" << endl;
        }
    }

    if(flag){
        cout << "Yes" << endl;
        rep2(i, 1, n){
            cout << sign[i] << endl;
        }
    }
    return 0;
}