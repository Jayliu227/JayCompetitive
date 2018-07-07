#include<bits/stdc++.h>

using namespace std;

long long n, k, state;
long long dp[10][100][(1 << 10)] = {0};

bool ok(int i){
    return ((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0);
}

bool fit(int cur, int last){
    if(ok(cur) && ok(last)){
        return (((cur & last) == 0) && (((cur << 1) & last) == 0) && (((cur >> 1) & last) == 0));
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    state = (1 << n);

    for(int i = 0; i < state; i++){
        if(ok(i)){
            dp[n - 1][k - __builtin_popcount(i)][i] = 1LL;
        }
    }

    for(int i = n - 1; i >= 1; i--){
        for(int p = 0; p < state; p++){
            for(int q = 0; q < state; q++){
                for(int num = 0; num <= k; num++){
                    if(fit(p, q) && (num - __builtin_popcount(p) >= 0)){
                        dp[i - 1][num - __builtin_popcount(p)][p] += dp[i][num][q] * 1LL;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < state; i++){
        ans += dp[0][0][i];
    }
    cout << ans << endl;
    return 0;
}