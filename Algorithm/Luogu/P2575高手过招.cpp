#include<bits/stdc++.h>
using namespace std;

int sg[(1 << 20) + 10];

int lb(int x){
    return x & -x;
}   

int a[21];
int helper(int x){
    if(sg[x] != -1) return sg[x];
    // clean all the choices that are impossible.
    int t = (x + 1) - lb(x + 1);
    int k = lb(t);
    int cnt = 0;
    int temp;
    // try every remaining chocies
    while(k){
        // get the right most untried piece and clean it
        t ^= k;
        // temp represents the piece pos from which we move it
        temp = k;
        // k represents the piece pos to which we move it
        // we need to find the first k such that when it xor
        // with x, it becomes smaller, so only when kth pos at x
        // is 0 (since kth is 1);
        while((x ^ k) < x) k >>= 1;
        // memorize the sg number
        a[cnt++] = helper(x ^ temp ^ k);
        k = lb(t);
    }

    sort(a,a+cnt);
    // do mex
    if (a[0]) return sg[x]=0;
    for (int i=1;i<cnt;i++)
        if (a[i]-a[i-1]>1) return sg[x]=a[i-1]+1;
    return sg[x]=a[cnt-1]+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(sg, -1, sizeof(sg));
    for(int i = 0; i <= 20; i++){
        sg[(1 << i) - 1] = 0;
    }
    for(int i = 0; i < (1 << 20); i++){
        if(sg[i] == -1)
            helper(i);
    }

    int T, n, m, x;
    cin >> T;
    while(T--){
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> m;
            int line = 0;
            for(int j = 0; j < m; j++){
                cin >> x;
                line |= (1 << (20 - x));
            }
            ans ^= sg[line];
        }
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}