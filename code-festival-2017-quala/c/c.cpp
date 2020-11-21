#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<int> a(26, 0);
    rep(i, h){
        string x;
        cin >> x;
        rep(j, w){
            a[x[j]-'a']++;
        }
    }

    string res = "Yes";

    int ind=0;
    rep(i, h/2){
        rep(j, w/2){
            while(ind<26){
                if (a[ind] >= 4){
                    a[ind] -= 4;
                    break;
                }else{
                    ind++;
                }
            }
        }
    }

    if(ind == 26){
        res = "No";
    }else{
        ind = 0;
        if((h|w)&1){
            if(h&1){
                rep(i, w/2){
                    while(ind < 26){
                        if(a[ind] >= 2){
                            a[ind] -= 2;
                            break;
                        }else{
                            ind++;
                        }
                    }
                }
            }

            if(w&1){
                rep(i, h/2){
                    while(ind < 26){
                        if(a[ind] >= 2){
                            a[ind] -= 2;
                            break;
                        }else{
                            ind++;
                        }
                    }
                }
            }
        }

        if(ind == 26){
            res = "No";
        }
    }

    cout << res << endl;
    return 0;
}