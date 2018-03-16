#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ll long long

using namespace std;

const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e5;

bitset<1000010> bs;
vi primes;
ll sieve_size;

void sieve(ll upperbound){
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    REP(i, 2, sieve_size + 1) if(bs[i]){
        for(int j = i * i; j <= sieve_size; j += i){
            bs[j] = 0;
        }        
        primes.push_back((int)i);
    }
}

ll numPF(ll n){
    ll ans = 0;
    int index = 0; int p = primes[index];
    while(p*p <= n){
        while(n % p == 0){
            ans++;
            n /= p;
        }
        p = primes[++index];
    }     
    if(n != 1) ans++;
    
    return ans;
}

// count how many distinct PF of n
int numDiffPF(ll n){
    int index = 0, pr = primes[index];
    
    while(pr * pr <= n){
        while(n % pr == 0){
            n /= pr;
        }
        pr = primes[++index];
    }
    
    if(n != 1) index++;

    return index;
}

ll sumPF(ll n){
    ll ans = 0;
    int index = 0, pr = primes[index];
    
    while(pr * pr <= n){
        while(n % pr == 0){
            ans += pr;
            n /= pr;
        }
        pr = primes[++index];
    }
    
    if(n != 1) ans += n;
    return ans;
}

// formula
/*
    times all the (power + 1) for each prime factor
*/
ll numOfDivisor(ll n){
    ll ans = 1;
    int index = 0, pr = primes[index];

    while(pr * pr <= n){
        int pwr = 0;
        while(n % pr == 0){
            pwr++;
            n /= pr;
        }
        ans *= (pwr + 1);
        
        pr = primes[++index];
    }
    
    if(n != 1) ans *= 2;

    return ans;
}


ll sumDivisor(ll n){
    ll sum = 1;
    int index = 0; 
    ll pr = primes[index];
    
    while(pr*pr <= n){
        ll pwr = 0;
        while(n % pr == 0){
            n /= pr;
            pwr++;
        }
        
        sum *= ((ll)pow((double)pr, pwr + 1.0) - 1) / (pr - 1);
        
        pr = primes[++index];
    }

    if(n != 1) sum *= ((ll)pow((double)n, 2.0) - 1) / (n - 1);
    
    return sum;
}

ll eulerPhi(ll n){
    return 0;

}

int main(){
    int start_s = clock();
//=======CODE GOES HERE============
    sieve(10000);
    
    cout << numPF(1200) << '\n'; 
    cout << numDiffPF(1200) << '\n';
    cout << sumPF(1200) << '\n';
    cout << numOfDivisor(60) << '\n';
    cout << sumDivisor(60) << '\n';
    
//=======CODE ENDS HERE============    
    int stop_s = clock();
    printf("time lapsed: %.3fs\n", (stop_s - start_s) / double(CLOCKS_PER_SEC));    
    return 0;
}