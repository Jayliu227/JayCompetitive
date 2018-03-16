#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))

using namespace std;

const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e5;

long long sieve_size;
bitset<1000000> bs;
vi primes;

void sieve(long long upperbound){
    sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    
    for(long long i = 2; i <= sieve_size; i++)if(bs[i]){
        for(long long j = i * i; j <= sieve_size; j+=i){
            bs[j] = 0;
        }        
        primes.push_back((int)i);
    }
}

bool isPrime(long long n){
    if(n <= sieve_size) return bs[n];
    forn(i, primes.size()){
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

int main(){
    int start_s = clock();
//=======CODE GOES HERE============
    sieve(1000000);
    cout << isPrime(2147483647)<< '\n';
    cout << isPrime(136117223861LL)<< '\n';
//=======CODE ENDS HERE============    
    int stop_s = clock();
    printf("time lapsed: %.3fs\n", (stop_s - start_s) / double(CLOCKS_PER_SEC));    
    return 0;
}