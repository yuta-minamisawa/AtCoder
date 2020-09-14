#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)
#define T 10

int main(){
    int k;
    long dp[10][10], sum[10], sum_table[10][10];
    cin >> k;
    rep(i, T){
        dp[0][i] = 1; 
    }
    sum[0] = 9;
    rep2(i, 1, T){
        sum[i] = sum[i-1];
        rep(j, T){
            if(j==0||j==9){
                if(j==0){
                    dp[i][j] = dp[i-1][0] + dp[i-1][1];
                }else{
                    dp[i][j] = dp[i-1][8] + dp[i-1][9];
                    sum[i] += dp[i][j];
                }
            }else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                sum[i] += dp[i][j];
            }
        }
    }

    

    rep(i, T-1){
        sum_table[i+1][0] = sum[i];
    }
    sum_table[0][0] = 0;

    rep(i, T){
        rep2(j, 1, T){
            sum_table[i][j] = sum_table[i][j-1] + dp[i][j];
        }
    }

    int digit;

    rep(i, T){
        if(k<=sum[i]){
            digit = i;
            //tmp = sum[i];
            break;
        }
    }

    int start = 9, tmp;

    for(int j=start;j>0;j--){   //最上位bit
        if(k>sum_table[digit][j-1]){
            cout << j;
            k -= sum_table[digit][j-1];
            // if(j!=1){
            //     start = j-1;
            // }else{
            //     start = 1;
            // }
            start = j - 1;
            break;
        }else{
            //tmp -= dp[i][j];
        }
    }

    for(int i=digit-1;i>=0;i--){
        for(int j=start;j<T;j++){
            if(k<=dp[i][j]){
                cout << j;
                if(j!=0){
                    start = j-1;
                }else{
                    start = 0;
                }
                break;
            }else{
                k -= dp[i][j];
                //tmp -= dp[i][j];
            }
        }
    }

    cout << endl;
    return 0;
}