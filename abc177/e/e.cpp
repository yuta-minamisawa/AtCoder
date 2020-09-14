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
    vector<int> GCD;
    cin >> n;
    vector<int> a, D(1e6 + 1);

  int cnt = 0;

    rep(i, n) {
        int x;
        cin >> x;
        if (x != 1) {
            cnt++;
        }
        a.push_back(x);
    }

    rep(i, 1e6+1){
        D[i] = i;
    }

    rep2(i, 2, 1e6+1){
        if(D[i]==i){
            rep3(j, i*2, 1e6+1, i){
                D[j] = i;
            }
        }
    }

    set<int> prime;

    bool flag = true;

    rep(i, n){
        int check = a[i];
        while(D[check] != check){
            if(prime.find(D[check])!=prime.end()){
                flag = false;
                break;
            }else{
                prime.insert(D[check]);
            }
            while(D[check]==D[check/D[check]]){
                check /= D[check];
            }
            check /= D[check];
        }
        if (prime.find(check) != prime.end()) {
          flag = false;
          break;
        } else {
            if(check!=1){
                prime.insert(check);
            }
         
        }
        if(!flag){
            break;
        }
    }

    if(flag){
        cout << "pairwise coprime" << endl;
    }else{
        int g = a[0];
        rep2(i, 1, n){
            g = gcd(g, a[i]);
        }
        if(g==1){
            cout << "setwise coprime" << endl;
        }else{
            cout << "not coprime" << endl;
        }
    }

    return 0;
}