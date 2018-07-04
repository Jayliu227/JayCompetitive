#include<bits/stdc++.h>

using namespace std;

const int N = 123456;

namespace Phi{
    int euler(int n){
        int ans = n;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                ans -= ans / i;
            while(n % i == 0)
                n /= i;
        }
        if(n > 1)
            ans -= ans / n;
        return ans;
    }

    vector<int> primes;
    int is_composite[N];
    int phi[N];

    int getPhi(){
        fill(is_composite, is_composite + N, false);
        for(int i = 2; i < N; i++){
            if(!is_composite[i]){
                primes.push_back(i);
                phi[i] = i - 1;
            }
            for(int j = 0; j < primes.size() && i * primes[j] < N; j++){
                is_composite[i * primes[j]] = true;
                if(i % primes[j] == 0){
                    phi[i * primes[j]] = phi[i] * primes[j];
                    break;
                }else{
                    phi[i * primes[j]] = phi[i] * phi[primes[j]];
                }
            }
        }   
    }
}

namespace Mu{
    vector<int> primes;
    int is_composite[N];
    int mu[N];

    int getMu(){
        fill(is_composite, is_composite + N, false);
        for(int i = 2; i < N; i++){
            if(!is_composite){
                primes.push_back(i);
                // there is only one prime, so it is (-1)^1
                mu[i] = -1;
            }
            for(int j = 0; j < primes.size() && primes[j] * i < N; i++){
                is_composite[primes[j] * i] = true;
                if(i % primes[j]){
                    // there are at least two equal primes, thus, it is not square free
                    mu[i * primes[j]] = 0;
                    break;
                }else{
                    mu[i * primes[j]] = mu[i] * mu[primes[j]];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}