#include <bits/stdc++.h>
#include <boost/foreach.hpp>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

typedef std::pair<int, int> value_type;

struct second_order {
    bool operator()(const value_type& x, const value_type& y) const {
        return x.second < y.second;
    }
};

int main(){
    int n;
    cin >> n;
    map<int, int> vodd, veve;
    rep(i, n){
        int v;
        cin >> v;
        if(i%2){
            veve[v]++;
        }else{
            vodd[v]++;
        }
    }

    priority_queue<value_type, std::vector<value_type>, second_order> qo, qe;
    pair<int, int> p;
    BOOST_FOREACH(p, vodd) {
        qo.push(p);
    }
    BOOST_FOREACH(p, veve) {
        qe.push(p);
    }
    value_type otop = qo.top();
    value_type etop = qe.top();
    qo.pop();
    qe.pop();
    if(otop.first!=etop.first){
        cout << n - otop.second - etop.second << endl;
    }else{
        int o = otop.second, e = etop.second;
        if(o > e){
            if(!qe.empty()){
                etop = qe.top();
            }else{
                etop.second = 0;
            }
        }else{
            if(o < e){
                if(!qo.empty()){
                    otop = qo.top();
                }else{
                    otop.second = 0;
                }
            }else{
                value_type otmp = qo.top(), etmp = qe.top();
                int o2 = otmp.second, e2 = etmp.second;
                if(o2 > e2){
                    otop.second = o2;
                    if(qo.empty()){
                        otop.second = 0;
                    }
                }else{
                    etop.second = e2;
                    if(qe.empty()){
                        etop.second = 0;
                    }
                }
            }
        }
        cout << n - otop.second - etop.second << endl;
    }
    return 0;
}