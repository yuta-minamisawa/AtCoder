#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

vector<int> eratos(int n);

int main()
{
    ll n;
    cin >> n;
    vector<int> prime = eratos((int)sqrt((double)n+9));
    ll cnt = 0;
    ll left = n;
    int ind = 0, p_size = prime.size();
    ll z = prime[0], nowz = prime[0];
    while(left!=1&&ind<p_size){
        while(true){
            if (left % nowz != 0)
            {
                break;
            }
            left /= nowz;
            //cout << left << endl;
            nowz *= z;
            cnt++;
        }
        ind++;
        if(ind==p_size){
            break;
        }
        z = prime[ind];
        nowz = prime[ind];
    }
    if(left<prime[p_size-1]){
        cout << cnt << endl;
    }else{
        cout << cnt + 1 << endl;
    }
    
    return 0;
}

vector<int> eratos(int n){
    vector<bool> prime(n, true);
    vector<int> primebox;
    prime[0] = false;
    prime[1] = false;
    rep2(i, 2, n){
        if(prime[i]==true){
            primebox.push_back(i);
            int out = i*2;
            while(out<n){
                prime[out] = false;
                out += i;
            }
        }
    }
    return primebox;
}