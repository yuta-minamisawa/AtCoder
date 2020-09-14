#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (long i = (s); i < (long)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    long n;
    long k;
    cin >> n >> k;
    vector<long> a;
    rep(i, n){
        long A;
        cin >> A;
        a.push_back(A-1);
    }
    vector<long> check(n, 0);
    long point=0;
    long first=0, sec=0;
    rep(i, n){
        if(check[point]==0){
            first++;
            check[point]++;
            point = a[point];
        }else{
            break;
        }
    }

    if(k < first){
        point = 0;
        rep(i, k){
            point = a[point];
        }
        cout << point + 1 << endl;
    }else{
        k -= first;

    rep(i, n){
        if(check[point]!=2){
            sec++;
            check[point]++;
            point = a[point];
        }else{
            break;
        }
    }

    long x = k % sec;

    rep(i, x){
        point = a[point];
    }

    cout << point + 1 << endl;
    }
    
    return 0;
}