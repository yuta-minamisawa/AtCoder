#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll x, y, a, b, c;
vector<ll> A, B, C;

ll solve();

int main()
{
    ll num;
    cin >> x >> y >> a >> b >> c;
    
    rep(i, a){
        cin >> num;
        A.push_back(num);
    }
    rep(i, b)
    {
        cin >> num;
        B.push_back(num);
    }
    rep(i, c)
    {
        cin >> num;
        C.push_back(num);
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    cout << solve() << endl;

    return 0;
}

ll solve(){
    int inda = 0, indb = 0, indc = 0, getc=0;
    ll res = 0, topa = A[inda], topb = B[indb], topc = C[indc];
    bool xf=true, yf=true, cf=true;
    while((x!=0||y!=0)&&x+y-getc!=0){
        if(xf&&yf){
            if(topa>topb){
                if(cf){
                    if(topa>topc){
                        res += topa;
                        topa = A[++inda];
                        x--;
                        //cout << re << endl;
                    }else{
                        res += topc;
                        if (indc + 1 == C.size())
                        {
                            cf = false;
                        }
                        else
                        {
                            topc = C[++indc];
                        }
                        getc++;
                    }
                }else{
                    res += topa;
                    topa = A[++inda];
                    x--;
                }
            }else{
                if (cf)
                {
                    if (topb > topc)
                    {
                        res += topb;
                        topb = B[++indb];
                        y--;
                    }
                    else
                    {
                        res += topc;
                        if (indc + 1 == C.size())
                        {
                            cf = false;
                        }
                        else
                        {
                            topc = C[++indc];
                        }
                        getc++;
                    }
                }else{
                    res += topb;
                    topb = B[++indb];
                    y--;
                }
            }
        }else{
            if(xf){
                if (cf)
                {
                    if (topa > topc)
                    {
                        res += topa;
                        topa = A[++inda];
                        x--;
                    }
                    else
                    {
                        res += topc;
                        if (indc + 1 == C.size())
                        {
                            cf = false;
                        }
                        else
                        {
                            topc = C[++indc];
                        }
                        getc++;
                    }
                }
                else
                {
                    res += topa;
                    topa = A[++inda];
                    x--;
                }
            }else{
                if (cf)
                {
                    if (topb > topc)
                    {
                        res += topb;
                        topb = B[++indb];
                        y--;
                    }
                    else
                    {
                        res += topc;
                        if (indc+1 == C.size())
                        {
                            cf = false;
                        }else{
                            topc = C[++indc];
                        }
                        getc++;
                    }
                }
                else
                {
                    res += topb;
                    topb = B[++indb];
                    y--;
                }
            }
        }
        //cout << res << endl;
        if(xf&&x==0){
            xf=false;
        }
        if (yf && y == 0)
        {
            yf = false;
        }
    }
    return res;
}
