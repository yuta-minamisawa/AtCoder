#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n, y;
    cin >> n >> y;
    int yukichi = y / 10000;
    for(int i = yukichi; i>=0; i--){
        int rest_money = y - 10000 * i;
        int rest_paper = n - i;
        int ichiyo = rest_money / 5000;
        for(int j = ichiyo; j>=0; j--){
            int last_money = rest_money - 5000 * j;
            int last_paper = rest_paper - j;
            if(last_money == 1000 * last_paper){
                printf("%d %d %d\n", i, j, last_paper);
                return 0;
            }
        }
    }
    printf("%d %d %d\n", -1, -1, -1);
    return 0;
}