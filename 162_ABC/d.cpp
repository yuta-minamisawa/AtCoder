#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int solve(int r, int g, int b, int** a, int i, int j);

int n;
string s;

int main(){
    cin >> n;
    cin >> s;
    int **a = new int*[3];
    rep(i, 3){
        a[i] = new int[n+1];
        a[i][0] = 0;
    }
    int r=0, g=0, b=0;
    rep(i, n){
        if(s[i]=='R'){
            r++;
        }else{
            if(s[i]=='G'){
                g++;
            }else{
                b++;
            }
        }
        a[0][i+1] = r;
        a[1][i+1] = g;
        a[2][i+1] = b;
    }

    int rf=0, gf=0, bf=0;
    long ans=0;
    rep(i, n-1){
        //cout << i << endl;
        if(s[i]=='R'){
            rf++;
        }else{
            if(s[i]=='G'){
                gf++;
            }else{
                bf++;
            }
        }
        rep2(j, i+1, n){
            if(s[j]=='R'){
                if(rf==0){
                    rf++;
                    ans += solve(rf, gf, bf, a, i+1, j+1);
                    rf--;
                }else{
                    continue;
                }
            }else{
                if(s[j]=='G'){
                    if(gf==0){
                        gf++;
                        ans += solve(rf, gf, bf, a, i+1, j+1);
                        gf--;
                    }else{
                        continue;
                    }
                }else{
                    if(s[j]=='B'){
                        if(bf==0){
                            bf++;
                            ans += solve(rf, gf, bf, a, i+1, j+1);
                            bf--;
                        }else{
                            continue;
                        }
                    }
                }
            }
        }
        rf=0;gf=0;bf=0;
    }

    cout << ans << endl;
    return 0;
}

int solve(int r, int g, int b, int **a, int i, int j){
    //cout << r << g << b << endl;
    int dis = j - i;
    if(r==0){
        if(j+dis<=n && s[j+dis-1]=='R'){
            return a[0][n] - a[0][j] - 1;
        }else{
            return a[0][n] - a[0][j];
        }
    }else{
        if(g==0){
            if(j+dis<=n && s[j+dis-1]=='G'){
                return a[1][n] - a[1][j] - 1;
            }else{
                return a[1][n] - a[1][j];
            }
        }else{
            if(j+dis<=n && s[j+dis-1]=='B'){
                return a[2][n] - a[2][j] - 1;
            }else{
                return a[2][n] - a[2][j];
            }
        }
    }
}