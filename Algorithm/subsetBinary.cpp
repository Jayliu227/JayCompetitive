#include<bits/stdc++.h>

using namespace std;

int N;
int main(){
    printf("generate subset from 1 to N\n");
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) arr[i] = i+1;
    
    // since the power set of a set with cardinality of N is 2^N
    // therefore, they are total of 1 << N that many subsets
    // everytime we increment 1 and check if that bit is set, if so we can
    // simply consider it being in the set, otherwise not.
    // but this is only useful if the cardinality is smaller or equal to 32
    for(int i = 0; i < (1<<N); i++){
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}