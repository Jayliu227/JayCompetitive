#include<bits/stdc++.h>

using namespace std;
int gcd(int a, int b){
    return b == 0? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

void swap(int& a, int& b){
    a ^= b;
    b ^= a;
    a ^= b;                      
}

const int maxn = 5000000;

int main(){
    vector<int> primes;
    vector<bool> is_composite(maxn, false);
    for(int i = 2; i < maxn; i++){
        if(!is_composite[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && i * primes[j] < maxn; j++){
            is_composite[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
    cout << "finished sieve" << endl;
}