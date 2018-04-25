#include<bits/stdc++.h>

using namespace std;

/*
    Greedy algorithm that calculates the max
    sum range within a unsorted array
*/

int main(){
    int N;
    cout << "number of elements: " << "\n";
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];

    int sum = 0, ans = 0;

    for(int i = 0; i < N; i++){
        sum += arr[i];
        ans = max(ans, sum);
        sum = sum < 0 ? 0 : sum;
    }

    cout << "Largest range sum in a subsequence is " << ans << "\n";
}